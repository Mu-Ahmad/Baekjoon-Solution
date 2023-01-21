import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n = int(input())
board = [[-2] * n for _ in range(n)]
starting_points = []

for i in range(n):
    temp = input()
    for j in range(n):
        if temp[j] == "X":
            board[i][j] = -1
            starting_points.append((i, j))

result = [0, 0, 0]


def dfs(x, y):
  
    if board[x][y] != -1:
        return  
  
    next_cells = []

    if x - 1 >= 0:
        next_cells.append((x - 1, y))
    if x - 1 >= 0 and y + 1 < n:
        next_cells.append((x - 1, y + 1))
    if y - 1 >= 0:
        next_cells.append((x, y - 1))
    if y + 1 < n:
        next_cells.append((x, y + 1))
    if x + 1 < n and y - 1 >= 0:
        next_cells.append((x + 1, y - 1))
    if x + 1 < n:
        next_cells.append((x + 1, y))

  
    around_colors = [0, 0, 0]
    for next_cell in next_cells:
        colored = board[next_cell[0]][next_cell[1]]
        if colored >= 0:
            around_colors[colored] = 1
  
    next_color = sum(around_colors)

  
    if next_color == 1 and around_colors[1] == 1:
        next_color = 0

  
    if next_color == 2:
        print(3)
        exit()

  
    board[x][y] = next_color
    result[next_color] = 1

  
    for next_cell in next_cells:
        dfs(next_cell[0], next_cell[1])

for starting_point in starting_points:
    dfs(starting_point[0], starting_point[1])

print(sum(result))