#!/usr/bin/python3
"""Interview prep"""


def makeChange(coins, total):
    """determine the fewest num of coins needed to meet a given amount total"""
    if total <= 0:
        return 0
    min_coins = 0
    coins.sort()
    while len(coins) != 0:
        min_coins += total // coins[-1]
        total = total % coins[-1]
        if total == 0:
            return min_coins
        coins.pop(-1)
    return -1
