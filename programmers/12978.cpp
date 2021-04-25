#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;


vector<vector<pair<int,int>>> graph;
int dijkstra(int N, int K){
    vector<int> distance(N, INF);
    vector<int> visit;
    visit.resize(N);
    priority_queue<pair<int, int>> pq;
    distance[0] = 0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int curr = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(w > distance[curr]) continue;
        if(visit[curr] == 1) continue;
        visit[curr] = 1;
        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i].second;
            int new_w = graph[curr][i].first;
            if(visit[next] != 1 && distance[next] > distance[curr] + new_w){
                distance[next] = distance[curr] + new_w;
                pq.push(make_pair(-distance[next], next));
            }
        }
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        if(distance[i] <= K) answer++; 
    }
    return answer;
}

int solution(int N, vector<vector<int> > road, int K) {
    vector<int> map;
    graph.resize(N);
    for(int i=0;i<road.size();i++){
        int first = road[i][0] - 1;
        int second = road[i][1] - 1;
        int w = road[i][2];
        graph[first].push_back(make_pair(w,second));
        graph[second].push_back(make_pair(w,first));
    }
    int answer;
    answer = dijkstra(N, K);
    
    
    return answer;
}