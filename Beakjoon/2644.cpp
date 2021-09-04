#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int bfs(int start, int end, int n){
    queue<int> q;
    vector<int> visit(n+1, -1);
    q.push(start);
    visit[start] = 0;
    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(int next : graph[curr]){
            if(visit[next] == -1){
                visit[next] = visit[curr] + 1;
                q.push(next);
            }
        }
    }
    return visit[end];
}

int main(){
    int n, m, a, b, x, y;
    cin>>n>>a>>b>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout<<bfs(a, b, n);
}