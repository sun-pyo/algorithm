#include <iostream>
#include <vector>
#include <queue>

#define INF 2700000000

using namespace std;

struct info{
    int next;
    int cost;
};
vector<long long> answer;
vector<int> visit;

vector<vector<info>> graph;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    answer[start] = 0;
    int curr;
    while(!pq.empty()){
        curr = pq.top().second;
        pq.pop();
        
        if(visit[curr] != 0) continue;

        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i].next;
            int cost = graph[curr][i].cost;

            if(visit[next] == 0){
                if(answer[next] > cost + answer[curr]){
                    answer[next] = cost + answer[curr];
                    pq.push(make_pair(answer[next], next));
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, start, end, cost;
    
    answer.resize(N+1);
    visit.resize(N+1);
    graph.resize(N+1);

    cin>>N>>M;
    info temp;
    for(int i=0;i<M;i++){
        cin>>start>>end>>cost;
        temp.next = end;
        temp.cost = cost;
        graph[start].push_back(temp);
    }
    cin>>start>>end;

    for(int i=1;i<=N;i++){
        answer[i] = INF;
    }

    dijkstra(start);

    cout<<answer[end]<<"\n";
}