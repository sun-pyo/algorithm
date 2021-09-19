from functools import cmp_to_key
import bisect
import sys

N, M = map(int, sys.stdin.readline().split(" "))

file_list = []
ext_dict = {}

for i in range(N):
    filename = sys.stdin.readline().strip().split(".")
    file_list.append(filename)

for i in range(M):
    ext = sys.stdin.readline().strip()
    ext_dict[ext] = 1

for i in range(N):
    if ext_dict.get(file_list[i][1]) == None:
        file_list[i].append(0)
    else:
        file_list[i].append(1)

def compare(a, b):
    if a[0] == b[0]:
        if (a[2] == 1 and b[2] == 1) or (a[2] == 0 and b[2] == 0):
            if a[1] < b[1]:
                return -1
            elif b[1] < a[1]:
                return 1
            else:
                return 0
        elif a[2] == 1:
            return -1
        else:
            return 1
    elif a[0] < b[0]:
        return -1
    else:
        return 1

answer = sorted(file_list, key=cmp_to_key(compare))

for ans in answer:
    sys.stdout.write('.'.join(ans[:2]) + "\n")