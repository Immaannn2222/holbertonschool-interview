#!/usr/bin/python3
""" task """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened"""
    res = []
    res.append(0)
    if boxes[0] == []:
        return False
    for i in range(len(boxes)):
        for j in boxes[i]:
            if j not in res and j < len(boxes) and j != i:
                res.append(j)
    if len(res) != len(boxes):
        return False
    return True
