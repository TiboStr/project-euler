# By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

#    3
#   7 4
#  2 4 6
# 8 5 9 3

# That is, 3 + 7 + 4 + 9 = 23.

triangle = []

with open("018-Maximum path sum I/triangle.txt") as file:
    for line in file:
        triangle.append([int(i) for i in line.rstrip("\n").split(" ")])

for r_index in range(1, len(triangle[1:])+1):
    for c_index in range(len(triangle[r_index])):

        last_index_of_prev_row = len(triangle[r_index-1]) - 1
        cols = [0 if c_index-1 < 0 else c_index-1,
                last_index_of_prev_row if c_index > last_index_of_prev_row else c_index]

        triangle[r_index][c_index] += max(triangle[r_index-1][c] for c in cols)

print(f"The maximum sum is {max(triangle[-1])}")
