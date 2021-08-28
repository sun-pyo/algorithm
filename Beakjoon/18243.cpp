#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

bool dfs(int start){
    queue<int> q;
    vector<int> visit(graph.size(), 0);
    q.push(start);
    int curr, maxDepth=0, visit_count=0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        maxDepth = max(maxDepth, visit[curr]);
        visit_count++;
        for(int next : graph[curr]){
            if(next != start && visit[next] == 0){
                visit[next] = visit[curr] + 1;
                q.push(next);
            }
        }
    }
    return (maxDepth<=6 && visit_count==visit.size());
}

int main(){
    int N, K;
    cin>>N>>K;
    graph.resize(N);
    int node1, node2;
    for(int i=0;i<K;i++){
        cin>>node1>>node2;
        node1--;
        node2--;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    bool is_small = true;
    for(int i=0;i<N;i++){
        if(!dfs(i)){
            is_small = false;
            break;
        }
    }
    if(is_small) cout<<"Small World!\n";
    else cout<<"Big World!\n";
}