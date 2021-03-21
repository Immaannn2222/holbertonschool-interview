#!/usr/bin/python3
""" chess q"""
import sys


if len(sys.argv) != 2:
    print("Usage: nq N")
    exit(1)

if not sys.argv[1].isdigit():
    print("N must be a number")
    exit(1)

if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)


def strategy_inplace(col, q):
    return col in q or any(abs(col - x) == len(q) - i for i, x in enumerate(q))


x = int(sys.argv[1])


def make_the_move(n):
    board_moves = [[]]
    for y in range(n):
        board_moves = [sol + [i + 1]
                       for sol in board_moves
                       for i in range(x)
                       if not strategy_inplace(i + 1, sol)]
    return board_moves


for answer in make_the_move(x):
    print(list(enumerate(answer, start=1)))
