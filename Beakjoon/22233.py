import sys

N, M = map(int, sys.stdin.readline().strip().split(" "))

memo = {}
answer = []

for i in range(N):
    key = sys.stdin.readline().strip()
    memo[key] = 1

memo_num = len(memo)

for i in range(M):
    keywords = sys.stdin.readline().strip().split(",")

    for keyword in keywords:
        if memo.get(keyword) != None:
            memo_num -= memo[keyword]
            memo[keyword] = 0

    answer.append(memo_num)

for i in range(len(answer)):
    sys.stdout.write(str(answer[i]) + "\n")