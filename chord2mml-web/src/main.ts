// Main TypeScript entry point for chord2mml-web
import init, { convert_chord } from '../public/wasm/chord2mml_wasm.js';

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

        // Parse simple MML format (e.g., "c;e;g")
        const notes = mml.split(';').map(n => n.trim()).filter(n => n.length > 0);
        
        // Note frequencies (middle octave, C4=261.63Hz)
        const noteFrequencies: { [key: string]: number } = {
            'c': 261.63, 'c+': 277.18, 'd': 293.66, 'd+': 311.13,
            'e': 329.63, 'f': 349.23, 'f+': 369.99, 'g': 392.00,
            'g+': 415.30, 'a': 440.00, 'a+': 466.16, 'b': 493.88,
            'c-': 493.88, 'd-': 277.18, 'e-': 311.13, 'f-': 329.63,
            'g-': 369.99, 'a-': 415.30, 'b-': 466.16
        };

        const now = audioContext.currentTime;
        const duration = 1.0; // 1 second

        // Play each note simultaneously (chord)
        notes.forEach((note) => {
            const freq = noteFrequencies[note.toLowerCase()];
            if (freq) {
                const oscillator = audioContext.createOscillator();
                const gainNode = audioContext.createGain();
                
                oscillator.type = 'sine';
                oscillator.frequency.setValueAtTime(freq, now);
                
                gainNode.gain.setValueAtTime(0.2, now);
                gainNode.gain.exponentialRampToValueAtTime(0.01, now + duration);
                
                oscillator.connect(gainNode);
                gainNode.connect(audioContext.destination);
                
                oscillator.start(now);
                oscillator.stop(now + duration);
                
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
let wasmInitialized = false;
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

async function updateOutput(chord: string) {
    if (!wasmInitialized) {
        output.textContent = 'WASM未初期化';
        output.classList.add('error');
        return;
    }

    try {
        const mml = convert_chord(chord);
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
        output.textContent = `エラー: ${error}`;
        output.classList.add('error');
    }
}

async function initialize() {
    try {
        // Initialize WASM module for chord2mml
        await init();
        wasmInitialized = true;
        
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
