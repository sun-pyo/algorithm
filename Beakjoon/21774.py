import sys
import bisect

N, Q = map(int, sys.stdin.readline().split(" "))

Log = [[] for _ in range(7)]

for i in range(N):
    time, level = sys.stdin.readline().split("#")
    Log[int(level)].append(time)

for i in range(1, 7):
    Log[i].sort()

for i in range(Q):
    start, end, level = sys.stdin.readline().split("#")
    res = 0
    for j in range(int(level), 7):
        l = bisect.bisect_left(Log[j], start)
        r = bisect.bisect_right(Log[j], end)
        res += r - l
    sys.stdout.write(str(res) + "\n")