#!/usr/bin/python3
"""UTF-8"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    # use tne encode-decode
    try:
        bytes(x & 255 for x in data).decode("UTF-8")
        return True
    except Exception:
        return False
