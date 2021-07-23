# What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

import math

grid = [[int(col) for col in row] for row in [row.split(" ") for row in open(
    "011-Largest product in a grid/grid.txt").read().split("\n")]]

adjacent = 4


def can_go_right(row, col):
    return col+adjacent <= len(grid[row])


def can_go_left(row, col):
    return col+1-adjacent >= 0


def can_go_down(row, col):
    return row+adjacent <= len(grid)


def can_go_up(row, col):
    return row+1-adjacent >= 0


def horizontal(row, col):
    out = math.inf * -1

    if can_go_right(row, col):
        out = math.prod(grid[row][col:col+adjacent])

    if can_go_left(row, col) >= 0:
        prod = math.prod(grid[row][col-adjacent+1:col+1])
        out = prod if prod > out else out
    return out


def vertical(row, col):
    out = math.inf * -1

    if can_go_down(row, col):
        out = math.prod([grid[row+i][col] for i in range(adjacent)])

    if can_go_up(row, col):
        prod = math.prod([grid[row-i][col] for i in range(adjacent)])
        out = prod if prod > out else out
    return out


def diagonal(row, col):
    out = math.inf * -1

    if can_go_down(row, col):
        if can_go_right(row, col):
            out = math.prod([grid[row+i][col+i] for i in range(adjacent)])

        if can_go_left(row, col):
            prod = math.prod([grid[row+i][col-i] for i in range(adjacent)])
            out = prod if prod > out else out

    if can_go_up(row, col):
        if can_go_right(row, col):
            prod = math.prod([grid[row-i][col+i] for i in range(adjacent)])
            out = prod if prod > out else out

        if can_go_left(row, col):
            prod = math.prod([grid[row-i][col-i] for i in range(adjacent)])
            out = prod if prod > out else out
    return out


max_product = math.inf * -1
for row_index, row in enumerate(grid):
    for col_index, col in enumerate(row):
        max_product = max(max_product, horizontal(row_index, col_index), vertical(
            row_index, col_index),  diagonal(row_index, col_index))

print(
    f"The greatest product of {adjacent} adjacent numbers in the same direction is {max_product}")
