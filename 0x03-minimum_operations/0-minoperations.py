#!/usr/bin/python3
""" calculation of minimum"""


def minOperations(n):
    """Returns an integer
    If n is impossible to achieve, return 0"""
    num_op = 0
    if n == 2:
        num_op = 2
    i = 2
    while n >= 2:
        while n % i == 0:
            num_op = num_op + i
            n = n / i
        i = i + 1
    return num_op
