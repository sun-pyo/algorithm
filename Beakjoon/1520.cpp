#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long DP[500][500];
int M, N;
vector<vector<int>> map;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int DFS(int x, int y){
    int new_x, new_y;
    if(DP[y][x] != -1) return DP[y][x];
    DP[y][x] = 0;
    for(int i=0;i<4;i++){
        new_x = x + X[i];
        new_y = y + Y[i];
        if(new_y < M && new_x < N && new_y >= 0 && new_x >= 0 && map[y][x] > map[new_y][new_x]){
            DP[y][x] += DFS(new_x, new_y);
        }
    }
    return DP[y][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>M>>N;
    map.resize(M);
    for(int i=0;i<M;i++){
        map[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            DP[i][j] = -1;
        }
    }

    DP[M-1][N-1] = 1;
    DFS(0,0);

    cout<<DP[0][0];

}