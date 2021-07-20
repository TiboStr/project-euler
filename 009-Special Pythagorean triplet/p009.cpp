#include <iostream>
/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a² + b² = c²
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

int main() {
    int sum = 1000;

    for (int c = 1; c < sum; c++) {
        for (int a = 0; a < c; a++) {
            int b = sum - a - c;
            if (c * c == a * a + b * b) {
                std::cout << "The product of a Pythogorean triplet for which a+b+c = " << sum << ": a*b*c = " << a << "*" << b << "*" << c << " = " << a * b * c << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Unable to find a Pythogorean triplet for which the sum of a, b and c equals " << sum << std::endl;
    return -1;
}
