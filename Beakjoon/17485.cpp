#include <iostream>
#include <vector>

using namespace std;

#define INF 100000

int DP[1001][1000][3];
int map[1001][1000];

int main(){
    int N, M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(j+1 < M) DP[i][j][0] = min(DP[i-1][j+1][1], DP[i-1][j+1][2]) + map[i][j];
            else DP[i][j][0] = INF;
            DP[i][j][1] = min(DP[i-1][j][0], DP[i-1][j][2]) + map[i][j];
            if(j-1 >= 0) DP[i][j][2] = min(DP[i-1][j-1][1], DP[i-1][j-1][0]) + map[i][j];
            else DP[i][j][2] = INF;
        }
    }
    int answer = INF;
    for(int i=0;i<M;i++){
        for(int j=0;j<3;j++){
            if(answer > DP[N][i][j] && DP[N][i][j] != 0) answer =  DP[N][i][j];
        }
    }
    cout<<answer;
}