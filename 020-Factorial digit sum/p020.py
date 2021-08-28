# n! means n × (n − 1) × ... × 3 × 2 × 1

# For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

# Find the sum of the digits in the number 100!

def faculty(n):
    return 1 if n == 1 else n*faculty(n-1)


def facorial_digit_sum(n):
    return sum(int(i) for i in str(faculty(n)))


if __name__ == "__main__":
    print(f"The sum of the digits of 100! equals {facorial_digit_sum(100)}")
