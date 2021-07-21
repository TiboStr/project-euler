/*
It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?
*/

let sums = 0;
function findNumberOfSums(i, n) {

    if (n == 0) {
        sums += 1;
        //console.log(arr);
    }

    for (let j = i; j <= n; j += 1) {
        //arr.push(j); // if you also want the terms of the sum (just add an extra array parameter to the function)
        findNumberOfSums(j, n - j);
        //arr.pop(); 
    }
}

var n = 100;
findNumberOfSums(1, n);
console.log(`${n} can be written as a sum of at least two positive integers in ${sums - 1} ways`);
