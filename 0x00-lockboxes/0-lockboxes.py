#!/usr/bin/python3
""" task """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened"""
    if boxes is None:
        return False
    res = []
    res.append(boxes[0])
    for i in range(len(boxes)):
        for j in boxes[i]:
            if j not in res and j < len(boxes) and j != i:
                res.append(j)
    if len(res) != len(boxes):
        return False
    return True
