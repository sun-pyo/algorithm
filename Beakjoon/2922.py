import sys

string = sys.stdin.readline().strip()

def solution(idx, ans, contain_L, count_j, count_m):
    if idx == len(string):
        if contain_L == 1:
            return ans
        else:
            return 0
    res = 0
    if string[idx] == '_':
        if count_m < 2:
            res += solution(idx+1, ans*5, contain_L, 0, count_m+1)
        if count_j < 2:
            res += solution(idx+1, ans*20, contain_L, count_j+1, 0)
        if count_j < 2:
            res += solution(idx+1, ans, 1, count_j+1, 0)
    elif string[idx] in ['A', 'E', 'I', 'O', 'U']:
        if count_m < 2:
            res += solution(idx+1, ans, contain_L, 0, count_m+1)
    elif string[idx] == 'L':
        if count_j < 2:
            res += solution(idx+1, ans, 1, count_j+1, 0)
    else:
        if count_j < 2:
            res += solution(idx+1, ans, contain_L, count_j+1, 0)

    return res

answer = solution(0, 1, 0, 0, 0)
sys.stdout.write(str(answer))