#!/usr/bin/python3
"""
0-pascal_triangle
"""
import math


def pascal_triangle(n):
    """list of lists of integers representing the Pascal’s triangle of n"""
    res = []
    if n <= 0:
        return []
    for i in range(n):
        line = []
        for j in range(i+1):
            fact = math.factorial(i) // (
                math.factorial(j) * math.factorial(i - j))
            line.append(fact)
        res.append(line)
    return res
