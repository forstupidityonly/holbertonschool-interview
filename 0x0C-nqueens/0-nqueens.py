#!/usr/bin/python3
"""N queens """
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


def nQueen(board, col):
    """recur place queen in every col"""
    if col == N:
        """queens are placed call solution"""
        solution(board)
        return True

    """place queen at every sqr in the row recur if isSafe"""
    for row in range(0, N):
        """if no queen threaten another"""
        if isSafe(board, row, col):
            """place queen in current square"""
            board[row][col] = 1
            """recur for next row"""
            nQueen(board, col + 1)
            """backtrack and remove the queen from the current square"""
            board[row][col] = 0
    return False


def isSafe(board, row, col):
    """Function to check if two queens threaten each other or not """
    for x in range(0, N):
        """rtn false if two queens are in same row or col"""
        if board[row][x] == 1 or board[x][col] == 1:
            return False
    """return false if two queens share the same `\` diagonal"""
    (i, j) = (row, col)
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1
    """return false if two queens share the same `/` diagonal"""
    (i, j) = (row, col)
    while i >= 0 and j < N:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1
    """all is safe so True"""
    return True


def solution(board):
    """print all queen positions once solved"""

    Positions = []

    for row in range(0, N):
        for col in range(0, N):
            if board[row][col] == 1:
                Positions.append([row, col])
    print(Positions)


nQueen(board, 0)
