/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

const assert = require('assert');

// I am too lazy to type: [1, 2, ..., 20]
let makeSequence = (lower, upper) => {
    assert(typeof lower === "number" && typeof upper === "number" && lower < upper, "invalid input");
    let out = [];
    for (let i = lower; i <= upper; i += 1) { out.push(i); }
    return out;
};

function lcmOfArray(arr) {
    let arrCopy = [...arr];
    arrCopy.sort().reverse();  // speed up arrCopy.every( ... )
    let max = arrCopy[0];

    while (true) {
        if (arrCopy.every(el => max % el === 0)) {
            return max;
        }
        max += 1;
    }
}

let seq = makeSequence(1, 20);

console.log(`The lcm of the numbers ${seq.slice(0, seq.length - 1)} and ${seq[seq.length - 1]} is ${lcmOfArray(seq)}.`);
