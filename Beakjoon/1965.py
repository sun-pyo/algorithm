import sys

N = int(sys.stdin.readline().rstrip())

arr = []
DP = [1 for _ in range(N)]
line = sys.stdin.readline().rstrip().split(" ")
for i in line:
    arr.append(int(i))

for i in range(N):
    for j in range(i):
        if arr[i] > arr[j]:
            DP[i] = max(DP[i], DP[j] + 1)

answer = 0
for i in DP:
    answer = max(answer, i)

sys.stdout.write(str(answer))