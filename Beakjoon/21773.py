import heapq
import sys

line = sys.stdin.readline().split(" ")
T = int(line[0])
n = int(line[1])

pq = []

for i in range(n):
    line = sys.stdin.readline().split(" ")
    A = int(line[0])
    B = int(line[1])
    C = int(line[2])

    heapq.heappush(pq, (-C, A, B))

for i in range(T):
    temp = heapq.heappop(pq)
    if temp[2] > 1:
        heapq.heappush(pq,(temp[0]+1, temp[1], temp[2]-1))
    sys.stdout.write(str(temp[1]) + "\n")


