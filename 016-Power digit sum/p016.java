/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

import java.math.BigInteger;

public class p016 {

    public static void main(String[] args) {
        int num = 2;
        int exp = 1000;
        BigInteger power = BigInteger.valueOf(num).pow(exp);

        long sum = power.toString().chars().mapToObj(i -> Integer.valueOf(i)).mapToInt(i -> i).sum();
        System.out.println("The sum of the digits of " + num + "^" + exp + " is " + sum);
    }

}