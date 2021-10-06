def dfs(edge, start):
    visit = [0 for _ in range(len(edge))]
    stack = []
    stack.append(start)
    count = 0
    while stack:
        curr = stack.pop()
        if visit[curr] == 1:
            continue
        visit[curr] = 1
        count += 1
        for next in range(1, len(edge)):
            if visit[next] == 0 and edge[curr][next] == 1:
                stack.append(next)
    return count
        

def solution(n, wires):
    answer = 100
    edge = [[0 for _ in range(n+1)] for _ in range(n+1)]
    
    for node1, node2 in wires:
        edge[node1][node2] = 1
        edge[node2][node1] = 1
        
    for node1, node2 in wires:
        edge[node1][node2] = 0
        edge[node2][node1] = 0
        
        count = dfs(edge, node1)
        answer = min(answer, abs(count - (n-count)))
        
        edge[node1][node2] = 1
        edge[node2][node1] = 1
        
    return answer