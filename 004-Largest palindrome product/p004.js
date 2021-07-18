/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

function isPalindrome(n) {
    return n + "" === (n + "").split("").reverse().join("");
}

function findPalindromeProduct(numberOfDigits) {
    let largestPalindrome = 0;
    let firstNum = Math.pow(10, numberOfDigits) - 1;
    let secondNum = Math.pow(10, numberOfDigits) - 1;

    while (firstNum >= 10 * numberOfDigits) {
        while (secondNum >= 10 * numberOfDigits && firstNum * secondNum > largestPalindrome) {
            let product = firstNum * secondNum;
            if (isPalindrome(product)) {
                largestPalindrome = product;
            }
            secondNum -= 1;
        }
        secondNum = 999;
        firstNum -= 1;
    }
    return largestPalindrome;
}

console.log("The largest palindrome made from te product of two 3-digit numbers is " + findPalindromeProduct(3));
