#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000000

using namespace std;

vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start){
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    priority_queue<pair<int ,int >> pq;
    pq.push({0, start});
    int w, curr, next, next_w;
    while(!pq.empty()){
        w = pq.top().first;
        curr = pq.top().second;
        pq.pop();
        if(dist[curr] < w) continue;
        for(int i=0;i<graph[curr].size();i++){
            next = graph[curr][i].first;
            next_w = graph[curr][i].second;
            if(dist[next] > w + next_w){
                dist[next] = w + next_w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}


int main(){
    int n, m, a, b, c;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    vector<vector<int>> answer;

    for(int i=1;i<=n;i++){
        answer.push_back(dijkstra(i));
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(answer[i][j] == INF) cout<<"0 ";
            else cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }

}