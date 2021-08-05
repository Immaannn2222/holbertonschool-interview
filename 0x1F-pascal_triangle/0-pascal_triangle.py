#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """list of lists of integers representing the Pascal’s triangle of n"""
    if n <= 0:
        return []
    res = []
    for i in range(n):
        res.append([1] * (i + 1))
    for i in range(2, n):
        for j in range(1, i):
            res[i][j] = res[i-1][j-1] + res[i-1][j]
    return res
