#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define INF 100000000;

int N, K;
vector<pair<int, int>> points;
int DP[501][500];

int getDistance(int idx1, int idx2){
    return abs(points[idx1].first - points[idx2].first) + abs(points[idx1].second - points[idx2].second);
}

int dfs(int pos, int skip){
    if(pos == N-1) return 0;
    if(DP[pos][skip] != -1) return DP[pos][skip];
    int distance;
    for(int i=0;i<=skip;i++){
        if(pos+i+1 >= N) continue;
        distance = dfs(pos+i+1, skip-i) + getDistance(pos, pos+i+1);
        if(DP[pos][skip]==-1 || DP[pos][skip] > distance)
            DP[pos][skip] = distance;
    }
    return DP[pos][skip];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        points.push_back({x, y});
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            DP[i][j] = -1;
        }
    }
    cout<<dfs(0, K);
}