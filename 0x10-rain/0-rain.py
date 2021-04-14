#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """ calculate how much water will be retained after it rains"""
    if len(walls) == 0:
        return 0
    retained_water = 0
    left = 0
    right = len(walls) - 1
    while left < right:
        retained_water = max(retained_water, min(
            walls[left], walls[right]) * (right - left - 1))
        if walls[left] < walls[right]:
            left += 1
        else:
            right -= 1
    return retained_water
