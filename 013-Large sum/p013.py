# Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

print(f"The first ten digits are: {str(sum([int(line) for line in open('013-Large sum/digit.txt')]))[0:10]}")