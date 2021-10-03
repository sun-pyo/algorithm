import sys

DP = []
n =0
m = 0
def solution(pre, idx, N, M):
    if idx == N:
        return 1
    if DP[idx][pre] != 0:
        return DP[idx][pre]
    DP[idx][pre] = 0
    if pre == 0:
        start = 1
    else:
        start = 2*pre
    end =  M//(pow(2, (N-idx-1)))
    for i in range(start, end+1):
        if i <= M:
            DP[idx][pre] += solution(i, idx+1, N, M)
    return DP[idx][pre]

    

T = int(sys.stdin.readline().strip())

for t in range(T):
    n, m = map(int, sys.stdin.readline().strip().split(" "))
    DP = [[0 for _ in range(m)] for _ in range(n+1)]
    answer = solution(0, 0, n, m)
    sys.stdout.write(str(answer) + '\n')
