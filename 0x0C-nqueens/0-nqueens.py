#!/usr/bin/python3
""" """
import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)


try:
    N = int(sys.argv[1])

except ValueError:
    print("N must be a number")
    sys.exit(1)


if (4 > N):
    print("N must be at least 4")
    sys.exit(1)

board = [[0 for i in range(0, N)] for j in range(0, N)]
print(board)
