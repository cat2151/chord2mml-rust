// Main TypeScript entry point for chord2mml-web
//
// Parsing pipeline (tonejs-mml-to-json pattern):
//   input → web-tree-sitter (JS) + tree-sitter-chord.wasm → CST JSON
//         → chord2mml-wasm convert_cst (Rust) → MML
import init, { convert_cst } from '../public/wasm/chord2mml_wasm.js';
import { Parser, Language } from 'web-tree-sitter';
import treeSitterWasmUrl from 'web-tree-sitter/web-tree-sitter.wasm?url';
import { nodeToCSTJson } from './cst-serializer.js';

// Simple audio sequencer using Web Audio API
interface AudioSequencer {
    play(mml: string): Promise<void>;
    stop(): void;
}

class SimpleAudioSequencer implements AudioSequencer {
    private audioContext: AudioContext | null = null;
    private oscillators: OscillatorNode[] = [];

    private getAudioContext(): AudioContext {
        if (!this.audioContext) {
            this.audioContext = new (window.AudioContext || (window as any).webkitAudioContext)();
        }
        return this.audioContext;
    }

    async play(mml: string): Promise<void> {
        const audioContext = this.getAudioContext();

        // Stop any currently playing notes
        this.stop();

        // Parse MML like "v11'c1eg''>c<ceg'" into a sequence of chords
        const chords = [...mml.matchAll(/'([^']*)'/g)].map(m => m[1]);

        // Note frequencies (middle octave, C4=261.63Hz); sharp '+' / flat '-'
        const noteFrequencies: { [key: string]: number } = {
            'c': 261.63, 'c+': 277.18, 'd': 293.66, 'd+': 311.13,
            'e': 329.63, 'f': 349.23, 'f+': 369.99, 'g': 392.00,
            'g+': 415.30, 'a': 440.00, 'a+': 466.16, 'b': 493.88,
            'c-': 246.94, 'd-': 277.18, 'e-': 311.13, 'f-': 329.63,
            'g-': 369.99, 'a-': 415.30, 'b-': 466.16
        };

        const now = audioContext.currentTime;
        const chordDuration = 1.0; // 1 second per chord

        chords.forEach((chordMml, chordIndex) => {
            const startTime = now + chordIndex * chordDuration;

            // Tokenize chord content: '<'/'>' shift octave, note letter with
            // optional '+'/'-', digits (note length) are skipped
            const notes: { name: string; octave: number }[] = [];
            let octave = 0;
            for (const m of chordMml.matchAll(/([<>])|([a-g][+-]?)|(\d+)/g)) {
                if (m[1] === '<') octave++;
                else if (m[1] === '>') octave--;
                else if (m[2]) notes.push({ name: m[2], octave });
            }

            notes.forEach(({ name, octave: noteOctave }) => {
                const baseFreq = noteFrequencies[name];
                const freq = baseFreq ? baseFreq * Math.pow(2, noteOctave) : undefined;
                if (freq) {
                    const oscillator = audioContext.createOscillator();
                    const gainNode = audioContext.createGain();

                    oscillator.type = 'sine';
                    oscillator.frequency.setValueAtTime(freq, startTime);

                    gainNode.gain.setValueAtTime(0.2, startTime);
                    gainNode.gain.exponentialRampToValueAtTime(0.01, startTime + chordDuration);

                    oscillator.connect(gainNode);
                    gainNode.connect(audioContext.destination);

                    oscillator.start(startTime);
                    oscillator.stop(startTime + chordDuration);

                    // Clean up oscillator when it ends
                    oscillator.onended = () => {
                        const index = this.oscillators.indexOf(oscillator);
                        if (index > -1) {
                            this.oscillators.splice(index, 1);
                        }
                    };

                    this.oscillators.push(oscillator);
                }
            });
        });
    }

    stop(): void {
        this.oscillators.forEach(osc => {
            try {
                osc.stop();
            } catch (e) {
                // Oscillator might already be stopped; ignore only InvalidStateError
                if (!(e instanceof DOMException && e.name === 'InvalidStateError')) {
                    console.error('Error while stopping oscillator:', e);
                }
            }
        });
        this.oscillators = [];
    }
}

// Application state
let parser: Parser | null = null;
let audioSequencer: AudioSequencer;

// Get DOM elements
const chordInput = document.getElementById('chordInput') as HTMLTextAreaElement;
const output = document.getElementById('output') as HTMLDivElement;
const playButton = document.getElementById('playButton') as HTMLButtonElement;
const stopButton = document.getElementById('stopButton') as HTMLButtonElement;
const status = document.getElementById('status') as HTMLDivElement;

function showStatus(message: string, type: 'success' | 'error') {
    status.textContent = message;
    status.className = `status show ${type}`;
    setTimeout(() => {
        status.classList.remove('show');
    }, 3000);
}

function convertChord(input: string): string {
    if (!parser) {
        throw new Error('パーサー未初期化');
    }
    const tree = parser.parse(input);
    if (!tree) {
        throw new Error('パースに失敗しました');
    }
    if (tree.rootNode.hasError) {
        throw new Error(`コード表記を解釈できません: ${input}`);
    }
    const cstJson = nodeToCSTJson(tree.rootNode);
    return convert_cst(JSON.stringify(cstJson));
}

async function updateOutput(chord: string) {
    const input = chord.trim();
    if (input.length === 0) {
        output.textContent = '';
        output.classList.remove('error');
        return;
    }

    try {
        const mml = convertChord(input);
        output.textContent = mml;
        output.classList.remove('error');

        // Auto-play the generated MML
        if (mml && audioSequencer) {
            try {
                await audioSequencer.play(mml);
            } catch (error) {
                console.error('Auto-play error:', error);
                // Don't show error status for auto-play failures
            }
        }
    } catch (error) {
        output.textContent = `エラー: ${error instanceof Error ? error.message : error}`;
        output.classList.add('error');
    }
}

async function initialize() {
    try {
        // Initialize the Rust WASM module (CST → MML conversion)
        await init();

        // Initialize web-tree-sitter and load the chord grammar
        await Parser.init({
            locateFile: () => treeSitterWasmUrl,
        });
        const language = await Language.load(
            new URL('tree-sitter-chord.wasm', new URL(import.meta.env.BASE_URL, location.href)).href
        );
        parser = new Parser();
        parser.setLanguage(language);

        // Initialize audio sequencer
        audioSequencer = new SimpleAudioSequencer();

        // Set up event listeners
        chordInput.addEventListener('input', async () => {
            await updateOutput(chordInput.value);
        });

        playButton.addEventListener('click', async () => {
            const mml = output.textContent;
            if (mml && !output.classList.contains('error')) {
                try {
                    await audioSequencer.play(mml);
                    showStatus('再生中...', 'success');
                } catch (error) {
                    const errorMessage = error instanceof Error ? error.message : String(error);
                    showStatus(`再生エラー: ${errorMessage}`, 'error');
                }
            }
        });

        stopButton.addEventListener('click', () => {
            audioSequencer.stop();
            showStatus('停止しました', 'success');
        });

        // Initial conversion
        await updateOutput(chordInput.value);

        showStatus('初期化完了', 'success');

    } catch (error) {
        console.error('Initialization error:', error);
        output.textContent = `初期化エラー: ${error}`;
        output.classList.add('error');
        showStatus('初期化エラー', 'error');
    }
}

// Start the application
initialize();
