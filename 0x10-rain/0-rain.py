#!/usr/bin/python3
"""given list of no-neg int reping 'retaining' walls calc vol watter held"""


def rain(walls):
    """given walls rtn vol watter held"""
    leng = len(walls)
    if leng == 0:
        return 0
    retained = 0
    for i in range(1, leng - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, leng):
            right = max(right, walls[j])
        retained += min(left, right) - walls[i]
    return retained
