def solution(a, b):
    answer = 0
    if a < b:
        small = a
        big = b
    else:
        small = b
        big = a
    for i in range(small, big+1):
        answer += i
    return answer