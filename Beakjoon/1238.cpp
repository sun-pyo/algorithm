#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;

struct info{
    int next;
    int w;
};

vector<vector<info>> graph; 
vector<vector<int>> dist;

void dijkstra(int start, int N){
    vector<int> visit;
    visit.resize(N+1);
    dist[start].resize(N+1);
    for(int i=1;i<=N;i++){
        dist[start][i] = INF;
    }

    priority_queue<pair<int, int>> pq;
    dist[start][start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        if(visit[curr] == 1) continue;
        visit[curr] = 1;
        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i].next;
            int w = graph[curr][i].w;

            if(visit[next] != 1 && dist[start][next] > w + dist[start][curr]){
                dist[start][next] = w + dist[start][curr];
                pq.push(make_pair(-dist[start][next], next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X;
    cin>>N>>M>>X;

    graph.resize(N+1);
    dist.resize(N+1);
    
    int start;
    info temp;
    for(int i=0;i<M;i++){
        cin>>start>>temp.next>>temp.w;
        graph[start].push_back(temp);
    }
    for(int i=1;i<=N;i++){
        dijkstra(i, N);
    }

    int answer = dist[X][1] + dist[1][X];
    for(int i=2;i<=N;i++){
        if(dist[X][i] + dist[i][X] > answer){
            answer = dist[X][i] + dist[i][X];
        }
    }

    cout<<answer;
}