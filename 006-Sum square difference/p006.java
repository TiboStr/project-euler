import java.util.stream.IntStream;

/*
The sum of the squares of the first ten natural numbers is,
1² + 2² + ... + 10² = 385

The square of the sum of the first ten natural numbers is,
(1+2+...+10)² = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
3025 - 385 = 2640

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

public class p006 {

    private long sumOfSquares(int num) {
        return IntStream.rangeClosed(1, num).mapToLong(i -> i * i).sum();
    }

    private long squareOfSum(int num) {
        return (long) Math.pow(IntStream.rangeClosed(1, num).sum(), 2);
    }

    public static void main(String[] args) {
        int num = 100;
        long sumSquares = new p006().sumOfSquares(num);
        long squareSum = new p006().squareOfSum(num);
        System.out.println("The difference between the sum of the squares of the first " + num
                + " natural numbers and the square of the sum is " + squareSum + " - " + sumSquares + " = "
                + (squareSum - sumSquares));
    }

}
