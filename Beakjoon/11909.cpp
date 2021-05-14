#include <iostream>
#include <vector>

#define INF 2000000000

using namespace std;

vector<vector<int>> map;
vector<vector<int>> DP;

int dx[] = {0, 1};
int dy[] = {1, 0};

void sol(int N){
    int next_x, next_y;
    DP[0][0] = 0; 
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            for(int i=0;i<2;i++){
                next_x = x + dx[i];
                next_y = y + dy[i];
                if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N){
                    if(map[y][x] > map[next_y][next_x] && DP[next_y][next_x] > DP[y][x]){
                        DP[next_y][next_x] = DP[y][x];
                    }
                    else if(map[y][x] <= map[next_y][next_x] && DP[next_y][next_x] > DP[y][x] + map[next_y][next_x] - map[y][x] + 1){
                        DP[next_y][next_x] = DP[y][x] + map[next_y][next_x] - map[y][x] + 1;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    map.resize(N);
    DP.resize(N);

    for(int i=0;i<N;i++){
        map[i].resize(N);
        DP[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            DP[i][j] = INF;
        }
    }
    sol(N);
    cout<<DP[N-1][N-1];

}