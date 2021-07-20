import functools

# The four adjacent digits in the 1000-digit number (see `digit.txt`)that have the greatest product are 9 × 9 × 8 × 9 = 5832.
# Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

large_digit = open(
    "008-Largest product in a series/digit.txt").read().rstrip("\n")

adjacent_digits = 13

largest_product = 0
largest_factors = []

for i in range(0, len(large_digit) - adjacent_digits + 1):

    digits = [int(el) for el in large_digit[i:i+adjacent_digits]]
    product = functools.reduce(lambda x, y: x*y, digits)

    if product > largest_product:
        largest_product = product
        largest_factors = digits

print(f"The {adjacent_digits} adjecent digits that have the greatest product are {largest_factors}, the product is {largest_product}.")
