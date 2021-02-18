#!/usr/bin/python3
"""UTF-8"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    for x in data:
        f = x & 255
    x = bytes(f).decode("UTF-8")
    if x:
        return True
    else:
        return False
