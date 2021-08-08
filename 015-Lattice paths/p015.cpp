/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <cmath>
#include <iostream>

using namespace std;

long numberOfpaths(int n);  // Calculate 2n choose n

int main() {
    int n = 20;
    cout << "There are " << numberOfpaths(n) << " routes in a " << n << "x" << n << " grid where you can only move to the right and down" << endl;
}

long numberOfpaths(int n) {
    long solution = 1;
    for (double i = 1; i <= n; i++) {
        solution *= ((2 * n) + 1 - i);
        solution /= i;
    }
    return solution;
}
