import sys

N = int(sys.stdin.readline().strip())

size = []
count = 1
tri = 1
num = 1

while num <= N:
    size.append(num)
    count += 1
    tri += count
    num = num + tri

DP = [300000 for _ in range(N+1)] 

for i in range(len(size)):
    DP[size[i]] = 1

for i in range(len(size)):
    for n in range(size[i], N+1):
        DP[n] = min(DP[n], DP[n - size[i]] + 1)

sys.stdout.write(str(DP[N]))