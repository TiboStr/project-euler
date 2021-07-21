import java.util.stream.LongStream;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

public class p010 {

    private static boolean isPrime(long num) {
        if (num <= 1 || (num % 2 == 0 && num != 2)) {
            return false;
        }

        for (int i = 3; i <= Math.ceil(Math.sqrt(num)); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        long upperBound = 2000000;
        long sum = LongStream.range(2, upperBound).filter(el -> isPrime(el)).sum();
        System.out.println("The sum of all the primes below " + upperBound + " is " + sum);
    }
}
