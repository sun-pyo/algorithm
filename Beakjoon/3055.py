import sys
from collections import deque

R, C = map(int, sys.stdin.readline().strip().split(" "))
T_map = [[0 for _ in range(C)] for _ in range(R)]
water = deque()
for i in range(R):
    line = sys.stdin.readline().strip()
    for j in range(len(line)):
        T_map[i][j] = line[j]
        if T_map[i][j] == '*':
            water.append((j, i))
        elif T_map[i][j] == 'S':
            D_c = j
            D_r = i


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def water_bfs():
    size = len(water)
    for _ in range(size):
        c, r = water.popleft()
        for i in range(4):
            next_c = c + dx[i]
            next_r = r + dy[i]
            if(next_r >= 0 and next_r < R and next_c >=0 and next_c < C and T_map[next_r][next_c] == '.'):
                T_map[next_r][next_c] = '*'
                water.append((next_c, next_r))

def bfs(start_x , start_y):
    q = deque()
    q.append((start_x, start_y))
    visit = [[0 for i in range(C)] for j in range(R)]
    visit[start_y][start_x] = 1
    while q:
        water_bfs()
        size = len(q)
        for i in range(size):
            x, y = q.popleft()
            for i in range(4):
                next_x = x + dx[i]
                next_y = y + dy[i]
                if(next_y >= 0 and next_y < R and next_x >=0 and next_x < C and visit[next_y][next_x] == 0):
                    if T_map[next_y][next_x] == 'D':
                        return visit[y][x]
                    elif T_map[next_y][next_x] == '.':
                        visit[next_y][next_x] = visit[y][x] + 1
                        q.append((next_x, next_y))
    return -1

answer = bfs(D_c, D_r)
if answer == -1:
    sys.stdout.write("KAKTUS")
else:
    sys.stdout.write(str(answer))