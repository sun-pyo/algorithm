#include <iostream>
#include <vector>
#include <queue>

#define INF 100001

using namespace std;

int dist[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<INF;i++){
        dist[i] = INF;
    }

    int N, K;
    cin>>N>>K;

    int start = N;
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(curr == K) continue;
        if(dist[curr] < w) continue;
        if(curr > K){
            if(dist[curr] + curr - K < dist[K]){
                dist[K] = dist[curr] + curr - K;
            }
            continue;
        }
        if(curr+1 <= 100000 && curr < K && dist[curr+1] > dist[curr] + 1){
            dist[curr+1] = dist[curr] + 1;
            pq.push(make_pair(-dist[curr+1], curr+1));
        }
        if(curr-1 >= 0 && dist[curr-1] > dist[curr] + 1){
            dist[curr-1] = dist[curr] + 1;
            pq.push(make_pair(-dist[curr-1], curr-1));
        }
        if(curr*2 <= 100000 && curr < K && dist[curr*2] > dist[curr] + 1){
            dist[curr*2] = dist[curr] + 1;
            pq.push(make_pair(-dist[curr*2], curr*2));
        }

    }

    cout<<dist[K];

}