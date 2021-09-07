#include <iostream>
#include <vector>

#define MOD 100000
using namespace std;

int DP[101][101][4] = {0,};

/*
DP[i][j][0] = 아래 아래
DP[i][j][1] = 아래 오른쪽
DP[i][j][2] = 오른쪽 오른쪽
DP[i][j][3] = 오른쪽 아래
*/

int main(){
    int W, H;
    cin>>W>>H;
    for(int i=1;i<=H;i++){
        DP[i][1][0] = 1;
    }
    for(int i=1;i<=W;i++){
        DP[1][i][2] = 1;
    }
    for(int i=2;i<=H;i++){
        for(int j=2;j<=W;j++){
            DP[i][j][0] = (DP[i-1][j][0] + DP[i-1][j][3])%MOD;
            DP[i][j][1] = DP[i][j-1][0];
            DP[i][j][2] = (DP[i][j-1][1] + DP[i][j-1][2])%MOD;
            DP[i][j][3] = DP[i-1][j][2];
        }
    }
    int answer = 0;
    for(int i=0;i<4;i++){
        answer = (answer + DP[H][W][i])%MOD;
    }
    cout<<answer;
}