#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """list of lists of integers representing the Pascal’s triangle of n"""
    if n < 0:
        return []
    line = []
    for i in range(n):
        x = 11 ** i
        line.append(x)
    for j in range(0, len(line)):
        line[j] = str(line[j])
    return line
