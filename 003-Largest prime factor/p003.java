/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

13195 % 5 = 0 (13195 = 5 * 2639)                    (2 and 3 are no divisors)
2639 % 7 = 0 (2639 = 7 * 377)                       (2, 3, 5 are no divisors)
377 % 13 = 0 (377 = 13 * 29)                        (2, 3, 5, 7, 9 are no divisors)
29 % 29 = 0 -> 29 is the largest prime factor       (only divisor is itself, so the number must be prime)
*/

class p003 {

    private long largestPrimeFactor(long num) {
        while (num % 2 == 0) {
            num /= 2;
        }

        long largestPrimeFactor = 2;
        long divisor = 3;
        while (num > 1) {
            while (num % divisor == 0) {
                num /= divisor;
                largestPrimeFactor = divisor;
            }
            divisor += 2; // move on to the next divisor if we can't divide anymore (must be odd)
        }
        return largestPrimeFactor;
    }

    public static void main(String[] args) {
        long num = 600851475143L;
        System.out.println("The largest primefactor of " + num + " is: " + new p003().largestPrimeFactor(num));
    }
}