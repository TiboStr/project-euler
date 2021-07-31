#include <iostream>
using namespace std;

/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

long collatzLength(long num);

int main() {
    long limit = 999999;
    long longestSeq = 1;
    long maxStartingNumber = 1;

    for (long i = 1; i <= limit; i++) {
        long seq = collatzLength(i);
        if (seq > longestSeq) {
            longestSeq = seq;
            maxStartingNumber = i;
        }
    }

    cout << maxStartingNumber;
}

long collatzLength(long num) {
    long length = 0;
    long i = num;
    while (i != 1) {
        if (i % 2 == 0) {
            i /= 2;
        } else {
            i = i * 3 + 1;
        }
        length++;
    }
    return length;
}
