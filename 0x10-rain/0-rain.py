#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """ calculate how much water will be retained after it rains"""
    if walls == [] or len(walls) == 0:
        return 0
    retianed_water = 0
    n_walls = len(walls)
    for i in range(n_walls):
        for j in range(i + 1, n_walls):
            retianed_water = max(
                retianed_water, min(walls[i], walls[j]) * (j - i - 1))
    return retianed_water
