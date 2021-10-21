#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2000000000

vector<vector<pair<int, int>>> graph;

int solution(int start){
    int curr, w, next, next_w;
    vector<int> visit(graph.size(), 0);
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<graph[start].size();i++){
        next = graph[start][i].first;
        w = graph[start][i].second;
        pq.push({-w, next});
    }
    while(!pq.empty()){
        curr = pq.top().second;
        w = -pq.top().first;
        pq.pop();
        visit[curr] = 1;
        if(curr == start) return w;
        for(int i=0;i<graph[curr].size();i++){
            next = graph[curr][i].first;
            next_w = w + graph[curr][i].second;
            if(visit[next] == 0){
                pq.push({-next_w, next});
            }
        }
    }
    return -1;
}

int main(){
    int V, E, a, b, c;
    cin>>V>>E;
    graph.resize(V);
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        a--;
        b--;
        graph[a].push_back({b, c});
    }
    int res, answer = INF;
    for(int i=0;i<V;i++){
        res = solution(i);
        if(res != -1) answer = min(answer, res);
    }
    if(answer == INF) cout<<"-1\n";
    else cout<<answer<<"\n";
}