
from collections import deque

N = int(input())

graph = [[] for _ in range(N+1)]
parents = [0 for _ in range(N+1)]

def bfs():
    q = deque()
    q.append(1);
    while q:
        curr = q.popleft()
        for next in graph[curr]:
            if parents[next] == 0 :
                parents[next] = curr
                q.append(next)


for i in range(N-1):
    line = input().split(" ")
    a = int(line[0])
    b = int(line[1])
    graph[a].append(b)
    graph[b].append(a)

bfs()

for i in range(2, N+1):
    print(parents[i])

