#!/usr/bin/python3
"""returns the perimeter of the island in grid where 1 is land and 0/edge is
   water perimeter does not include diagonals there are no lakes and only one
   island is present"""


def island_perimeter(grid):
    """finds perimeter"""
    gHeight = len(grid)
    gLength = len(grid[0])

    def dfs(row, col):
        """rtn the perimeter for one island cell"""
        if (row < 0 or row >= gHeight or col < 0 or col >= gLength or
                grid[row][col] == 0):
            return 1
        if grid[row][col] == 1:
            grid[row][col] = 2
            return dfs(row - 1, col) + dfs(row + 1, col) + \
                dfs(row, col - 1) + dfs(row, col + 1)
        return 0

    perimeter = 0
    for row in range(gHeight):
        for col in range(gLength):
            if grid[row][col] == 1:
                perimeter += dfs(row, col)
    return perimeter
