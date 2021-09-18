import sys

N, Q = map(int, sys.stdin.readline().split(" "))

card_order = []
command = []
count = [-1 for _ in range(N)]

for i in range(N):
    line = list(map(int, sys.stdin.readline().split(" ")))
    card_order.append(line[1:])

for i in range(Q):
    line = sys.stdin.readline()
    command.append(line)

answer = set()

def do(string, cmd):
    x = cmd[4]
    cmd = cmd[:3]
    if cmd == "ADD":
        return string + x
    elif cmd == "DEL":
        x = int(x)
        to_list = list(string)
        if len(to_list) > x:
            del to_list[x]
            return ''.join(to_list)
        else:
            return "ERROR"


def do_command(string, card_num):
    card_num = card_num - 1
    cmd = command[card_num].split(",")
    s = string
    for i in range(len(cmd)):
        s = do(s, cmd[i])
        if s == "ERROR":
            return s
    return s

def dfs(cnt, string, used):
    if cnt == Q:
        if string == "":
            answer.add("EMPTY")
        else:
            answer.add(string)
        return

    for i in range(N):
        if used[i] + 1 < len(card_order[i]):
            used[i] += 1
            s = do_command(string, card_order[i][used[i]])
            if s != "ERROR":
                dfs(cnt+1, s, used.copy())
            else:
                answer.add("ERROR")
            used[i] -= 1

dfs(0, "", count)

ans = list(answer)
ans.sort()
for i in range(len(ans)):
    sys.stdout.write(str(ans[i]) + '\n')