import sys
from pprint import pprint
from itertools import combinations
from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n, m = (int(x) for x in input().split())

grid = list()
for i in range(n):
	grid.append([int(x) for x in input().split()])

def spread(viruses):
	q = deque(viruses)
	visited = [[-1 for _ in range(n)] for _ in range(n)]

	for x, y in q:
		visited[x][y] = 0

	m = 0
	while len(q) > 0:
		x, y = q.popleft()
		for i in range(4):
			ax = x + dx[i]
			ay = y + dy[i]

			if 0 <= ax < n and 0 <= ay < n:
				if visited[ax][ay] == -1 and grid[ax][ay] != 1:
					q.append([ax, ay])
					visited[ax][ay] = visited[x][y] + 1
					m = max(m, visited[ax][ay])

	for i in range(n):
		for j in range(n):
			if visited[i][j] == -1 and grid[i][j] != 1:
				return float("inf")
	return m

v = []
for i in range(n):
	for j in range(n):
		if grid[i][j] == 2:
			v.append([i, j])

ans = float('inf')
for comb in combinations(v, m):
	ans = min(ans, spread(comb))

if ans == float('inf'):
	print(-1)
else:
	print(ans)