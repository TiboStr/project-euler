# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

import itertools

print(f'The 1000000th permutation is {sorted(["".join(perm) for perm in itertools.permutations("0123456789", 10)])[999999]}')
