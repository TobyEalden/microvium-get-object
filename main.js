import {exportToC, generate, importFromC} from './ffi.js'

const intToString = importFromC('string', 'intToString', [['int','val']]);
const floatToString = importFromC('string', 'floatToString', [['float','val']]);

const floatLog = importFromC('void', 'floatLog', [['float', 'val']]);
const stringLog = importFromC('void', 'stringLog', [['string', 'val']]);

function log(idx, fib) {
    // floatLog(fib);
    stringLog(`{"idx": ${intToString(idx++)}, "fib": ${floatToString(fib)}`);
}

function fibonacci(limit) {
    let idx = 0;

    let first = 0.0;
    log(idx++, first);

    let second = 1.0;
    log(idx++, second);

    let fib = 0.0;
    while (idx < limit) {
        fib = second + first;
        first = second;
        second = fib;
        log(idx++, fib);
    }
}

exportToC('void', 'fibonacci', [['int', 'limit']], fibonacci);

generate("Experiment1");

