#include <iostream>
#include <cstring>
#include <vector>

#define INF 2000000000

using namespace std;

int K, N;
int cost[101][2];
int time[101][2];
int DP[101][100001];

int dfs(int idx, int t){
    if(t > K) return -INF;
    if(idx == N) return 0;
    if(DP[idx][t] != -1) return DP[idx][t];
    DP[idx][t] = max(dfs(idx+1, t+time[idx][0])+cost[idx][0], dfs(idx+1, t+time[idx][1])+cost[idx][1]);
    return DP[idx][t];
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>time[i][0]>>cost[i][0]>>time[i][1]>>cost[i][1];
    }
    memset(DP, -1, sizeof(DP));
    cout<<dfs(0, 0);
}