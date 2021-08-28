import java.util.stream.IntStream;

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

public class p021 {

    public int sumOfProperDivisors(int n) {
        return IntStream.range(1, n).filter(i -> n % i == 0).sum();
    }

    public static void main(String[] args) {
        p021 object = new p021();
        int sum = 0;
        for (int i = 1; i < 10000; i++) {
            int dn = object.sumOfProperDivisors(i);
            if (i != dn && object.sumOfProperDivisors(dn) == i) {
                sum += i;
            }
        }
        System.out.println("The sum of all the amical numbers under 10000 equals " + sum);
    }

}