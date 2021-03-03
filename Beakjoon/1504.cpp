#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;

void dijkstra(int start, int j){
    priority_queue<pair<int, int>> pq;
    dist[j][start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_w = pq.top().first;
        pq.pop();
        if(dist[j][curr] < curr_w) continue;

        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i].second;
            int w = graph[curr][i].first;
            if(dist[j][next] > dist[j][curr] + w){
                dist[j][next] = dist[j][curr] + w;
                pq.push(make_pair(-w, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    cin>>N>>E;

    graph.resize(N+1);
    dist.resize(3);
    
    int a,b,c;

    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(c,b));
        graph[b].push_back(make_pair(c,a));
    }

    vector<int> start;
    start.resize(3);
    start[0] = 1;
    cin>>start[1]>>start[2];

    for(int j=0;j<3;j++){
        dist[j].resize(N+1);
        for(int i=1;i<=N;i++){
            dist[j][i] = INF;
        }
        dijkstra(start[j], j);
    }
    int answer = INF;
    if(dist[0][start[1]] != INF && dist[1][start[2]] != INF && dist[2][N] != INF && answer > dist[0][start[1]] + dist[1][start[2]] + dist[2][N]){
        answer = dist[0][start[1]] + dist[1][start[2]] + dist[2][N];
    }
    if(dist[0][start[2]] != INF && dist[2][start[1]] != INF && dist[1][N] != INF && answer > dist[0][start[2]] + dist[2][start[1]] + dist[1][N]){
        answer = dist[0][start[2]] + dist[2][start[1]] + dist[1][N];
    }
    if(answer >= INF || answer < 0) cout<<-1<<"\n";
    else cout<<answer<<"\n";
}