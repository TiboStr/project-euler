/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool isAbdundant(int num) {
    vector<int> divisors;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisors.push_back(i);
        }
    }

    int sum = 0;
    for_each(divisors.begin(), divisors.end(), [&](int i) {
        sum += i;
    });

    return sum > num;
}

int main() {
    unordered_set<int> abdundants;
    for (int i = 1; i < 28123; i++) {
        if (isAbdundant(i)) {
            abdundants.insert(i);
        }
    }

    int sum = 0;
    for (int i = 0; i < 28123; i++) {
        bool canBeSum = false;
        for (int a : abdundants) {
            if (a < i && abdundants.find(i - a) != abdundants.end()) {
                canBeSum = true;
                break;
            }
        }
        if (!canBeSum) {
            sum += i;
        }
    }

    cout << "The sum of all positive integer which cannot be written as the sum of two abdundant numbers is " << sum << endl;
    return 0;
}
