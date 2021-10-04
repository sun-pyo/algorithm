import sys

N = int(sys.stdin.readline())

def check(s):
    size = len(s)
    for n in range(1, size//2+1):
        if (s[size-2*n:size-n]) == (s[size-n:size]):
            return False
    return True

def solution(s):
    if len(s) == N:
        sys.stdout.write(str(s))
        return True
    for num in range(1, 4):
        if check(s + str(num)):
            if solution(s + str(num)):
                return True

solution("1")
