#!/usr/bin/python3
"""Interview Prep"""


def rotate_2d_matrix(matrix):
    """rotate n x n 2D mmatrix 90 degrees clockwise"""
    new = list(zip(*matrix[::-1]))
    matrix.clear()
    for i in range(len(new)):
        matrix.append((list(new[i])))
