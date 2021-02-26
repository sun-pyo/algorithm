#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647

using namespace std;

struct edge{
    int next;
    int weight;
};
vector<int> dist;
vector<int> visit;
vector<vector<edge>> graph;

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    int curr;
    while(!pq.empty()){
        curr = pq.top().second;
        pq.pop();
        
        if(visit[curr] == 1) continue;

        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i].next;
            int w = graph[curr][i].weight;

            if(visit[next] != 1 && dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin>>V>>E;
    cin>>K;

    graph.resize(V+1);
    dist.resize(V+1);
    visit.resize(V+1);

    int u, v, w;
    for(int i=1;i<=E;i++){
        cin>>u>>v>>w;
        edge e;
        e.next = v;
        e.weight = w;
        graph[u].push_back(e);
    }    

    for(int i=1;i<=V;i++){
        dist[i] = INF;
    }

    dijkstra(K);

    for(int i=1;i<=V;i++){
        if(dist[i] == INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
}