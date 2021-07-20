#include <cmath>
#include <iostream>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

bool isPrime(int num) {
    if (num <= 1 or (num % 2 == 0 && num != 2)) {
        return false;
    }

    for (int i = 3; i <= ceil(sqrt(num)); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int goal = 10001;  // nth prime we are looking for
    int current = 0;   // number of primes we have found so far
    int currentPrime;

    // assume that the variable goal >= 1
    int i = 2;
    while (current != goal) {
        if (isPrime(i)) {
            current += 1;
            currentPrime = i;
        }
        i++;
    }

    std::cout << "The nth prime with n equals " << goal << " is " << currentPrime << "." << std::endl;
}