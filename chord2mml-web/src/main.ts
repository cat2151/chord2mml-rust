// Main TypeScript entry point for chord2mml-web
import init, { convert_chord } from '../public/wasm/chord2mml_wasm.js';

// Simple audio sequencer using Web Audio API.
// Note: tonejs-mml-to-json and tonejs-json-sequencer are declared in package.json
// for potential future use in Phase 3; they are intentionally not integrated here,
// which uses a minimal Web Audio API implementation for the basic demo.

interface AudioSequencer {
    play(mml: string): void;
    stop(): void;
}

class SimpleAudioSequencer implements AudioSequencer {
    private audioContext: AudioContext | null = null;
    private oscillators: OscillatorNode[] = [];

    constructor() {
        // AudioContext will be created on first user interaction
    }

    private ensureAudioContext(): AudioContext {
        if (!this.audioContext) {
            this.audioContext = new AudioContext();
        }
        return this.audioContext;
    }

    private noteToFrequency(note: string): number {
        // Simple mapping of note names to frequencies (C4 = middle C)
        const noteMap: { [key: string]: number } = {
            'c': 261.63,  // C4
            'd': 293.66,  // D4
            'e': 329.63,  // E4
            'f': 349.23,  // F4
            'g': 392.00,  // G4
            'a': 440.00,  // A4
            'b': 493.88,  // B4
        };
        const normalizedNote = note.toLowerCase().trim();
        return noteMap[normalizedNote] || 440;
    }

    play(mml: string): void {
        this.stop(); // Stop any currently playing notes

        const ctx = this.ensureAudioContext();
        const notes = mml.split(';').map(n => n.trim()).filter(n => n.length > 0);
        
        const now = ctx.currentTime;
        const duration = 2.0;
        
        // Clear old oscillators before creating new ones
        this.oscillators = [];
        
        notes.forEach(note => {
            const oscillator = ctx.createOscillator();
            const gainNode = ctx.createGain();
            
            oscillator.type = 'sine';
            oscillator.frequency.value = this.noteToFrequency(note);
            
            gainNode.gain.setValueAtTime(0.3, now);
            gainNode.gain.exponentialRampToValueAtTime(0.01, now + duration);
            
            oscillator.connect(gainNode);
            gainNode.connect(ctx.destination);
            
            oscillator.start(now);
            oscillator.stop(now + duration);
            
            // Clean up when oscillator ends
            oscillator.onended = () => {
                const index = this.oscillators.indexOf(oscillator);
                if (index > -1) {
                    this.oscillators.splice(index, 1);
                }
            };
            
            this.oscillators.push(oscillator);
        });
    }

    stop(): void {
        this.oscillators.forEach(osc => {
            try {
                osc.stop();
            } catch (e) {
                // Oscillator might already be stopped
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
        // Initialize WASM module
        await init();
        wasmInitialized = true;
        
        // Initialize audio sequencer
        audioSequencer = new SimpleAudioSequencer();
        
        // Set up event listeners
        chordInput.addEventListener('input', () => {
            updateOutput(chordInput.value);
        });

        playButton.addEventListener('click', () => {
            const mml = output.textContent;
            if (mml && !output.classList.contains('error')) {
                audioSequencer.play(mml);
                showStatus('再生中...', 'success');
            }
        });

        stopButton.addEventListener('click', () => {
            audioSequencer.stop();
            showStatus('停止しました', 'success');
        });

        // Initial conversion
        updateOutput(chordInput.value);
        
        output.textContent = 'Ready! 初期化完了';
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
