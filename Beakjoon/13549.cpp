#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[150000];

bool check(int num){
    if(num >= 0 && num < 150000 && visit[num] == 0) return true;
    return false;
}

int bfs(int N, int K){
    priority_queue<pair<int, int>> pq;
    pq.push({0, N});
    int dist, curr, next;
    while(!pq.empty()){
        dist = -pq.top().first;
        curr = pq.top().second;
        pq.pop();
        
        if(curr == K) return dist;
        if(visit[curr] != 0) continue;
        visit[curr] = 1;
        for(int i=0;i<2;i++){
            if(i==0) next = curr + 1;
            else next = curr - 1;
            if(N != next && check(next)){
                pq.push({-(dist+1), next});
            }
        }
        next = curr*2;
        if(N != next && check(next)){
            pq.push({-dist, next});
        }
    }
    return 0;
}

int main(){
    int N, K;
    cin>>N>>K;
    cout<<bfs(N, K);
}