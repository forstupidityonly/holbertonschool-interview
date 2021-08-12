#!/usr/bin/python3
"""In a text file, there is a single character H. Your text editor can
execute only two operations in this file: Copy All and Paste"""


def minOperations(n):
    """Calculates the fewest number of operations needed to
            result in exactly n H characters in the file."""
    val = 1
    cpy = 0
    num_oprn = 0
    if not isinstance(n, int) or n < 2:
        return 0
    else:
        for i in range(n):
            if val == n:
                return num_oprn
            elif n % val == 0:
                cpy = val
                val += cpy
                num_oprn += 2
            else:
                val += cpy
                num_oprn += 1
