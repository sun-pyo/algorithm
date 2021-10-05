import sys
from collections import deque

def bfs(start_x, start_y, paper, N, M):
    q = deque()
    q.append((start_x, start_y))
    visit = [[0 for _ in range(M)] for _ in range(N)]
    while q:
        x, y = q.popleft()
        paper[y][x] = -1
        if visit[y][x] == 1:
            continue
        visit[y][x] = 1
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            next_x = x + dx
            next_y = y + dy
            if 0 <= next_x < M and 0 <= next_y < N and visit[next_y][next_x] == 0 and paper[next_y][next_x] != 1:
                q.append((next_x, next_y))



N, M = map(int, sys.stdin.readline().strip().split(" "))
paper = []

for i in range(N):
    paper.append(list(map(int ,sys.stdin.readline().strip().split(" "))))

answer = 0
do = True
while do:
    do = False
    bfs(0, 0, paper, N, M)
    remove_list = []
    for i in range(1, N):
        for j in range(1, M):
            if paper[i][j] == 1:
                do = True
                count = 0
                for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    next_x = j + dx
                    next_y = i + dy
                    if paper[next_y][next_x] == -1:
                        count += 1
                if count >= 2:
                    remove_list.append((j, i))
    
    for x, y in remove_list:
        paper[y][x] = -1
    if do == False:
        break
    answer += 1

sys.stdout.write(str(answer))

