import sys

Map = []

line = sys.stdin.readline().split(" ")
R = int(line[0])
C = int(line[1])
T = int(line[2])

dx = [0, 0, 0, 1, -1]
dy = [0, 1, -1, 0, 0]

for i in range(R):
    Map.append(sys.stdin.readline())

def dfs(x, y, t, count, visit):
    if Map[y][x] == 'S' and (x, y) not in visit:
        visit.append((x, y))
        count+=1
    if(t == T):
        return count
    res = 0
    for i in range(5):
        next_x = x + dx[i]
        next_y = y + dy[i]
        if next_x >= 0 and next_x < C and next_y >= 0 and next_y < R and Map[next_y][next_x] != '#':
            res = max(res, dfs(next_x, next_y, t+1, count, visit.copy()))
    return res

for i in range(R):
    for j in range(C):
        if(Map[i][j] == 'G'):
            answer = dfs(j, i, 0, 0, [])


sys.stdout.write(str(answer))