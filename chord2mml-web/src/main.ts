// Main TypeScript entry point for chord2mml-web
import init, { convert_chord } from '../public/wasm/chord2mml_wasm.js';
import { initWasm, mml2json } from 'tonejs-mml-to-json';
import * as Tone from 'tone';

// Type definition for tonejs-mml-to-json output
interface MMLNote {
    time: number;
    duration: number;
    name: string;
}

interface MMLTrack {
    notes: MMLNote[];
}

interface MMLJson {
    tracks: MMLTrack[];
}

// Audio sequencer using tonejs-mml-to-json and Tone.js
interface AudioSequencer {
    play(mml: string): Promise<void>;
    stop(): void;
}

class ToneJSSequencer implements AudioSequencer {
    private synth: Tone.PolySynth | null = null;

    constructor() {
        // Initialize Tone.js synth
        this.synth = new Tone.PolySynth(Tone.Synth).toDestination();
    }

    async play(mml: string): Promise<void> {
        if (!this.synth) return;

        // Stop any currently playing notes
        this.stop();

        // Ensure audio context is started (required for user interaction)
        await Tone.start();

        try {
            // Convert MML to JSON using tonejs-mml-to-json
            const json = mml2json(mml) as MMLJson;
            
            // Play the JSON sequence using Tone.js
            const now = Tone.now();
            
            if (json.tracks && json.tracks.length > 0) {
                const track = json.tracks[0];
                if (track.notes && Array.isArray(track.notes)) {
                    track.notes.forEach((note: MMLNote) => {
                        const time = now + (note.time || 0);
                        const duration = note.duration || 0.5;
                        const noteName = note.name || 'C4';
                        
                        this.synth!.triggerAttackRelease(noteName, duration, time);
                    });
                }
            }
        } catch (error) {
            console.error('Error playing MML:', error);
            throw error;
        }
    }

    stop(): void {
        if (this.synth) {
            this.synth.releaseAll();
        }
    }
}

// Application state
let wasmInitialized = false;
let mmlToJsonInitialized = false;
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

function updateOutput(chord: string) {
    if (!wasmInitialized) {
        output.textContent = 'WASM未初期化';
        output.classList.add('error');
        return;
    }

    try {
        const mml = convert_chord(chord);
        output.textContent = mml;
        output.classList.remove('error');
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
        
        // Initialize WASM module for tonejs-mml-to-json
        await initWasm();
        mmlToJsonInitialized = true;
        
        // Initialize audio sequencer
        audioSequencer = new ToneJSSequencer();
        
        // Set up event listeners
        chordInput.addEventListener('input', () => {
            updateOutput(chordInput.value);
        });

        playButton.addEventListener('click', async () => {
            const mml = output.textContent;
            if (mml && !output.classList.contains('error') && mmlToJsonInitialized) {
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
        updateOutput(chordInput.value);
        
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
