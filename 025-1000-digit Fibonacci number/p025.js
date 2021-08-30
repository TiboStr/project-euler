/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

let num1 = BigInt(1), num2 = BigInt(1), index = 3;

while ((num1 + num2).toString().length < 1000) {
    [num1, num2, index] = [num2, num1 + num2, index + 1];
}

console.log(`Index is: ${index}`);


