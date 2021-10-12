#include <vector>
#include <iostream>
#include <cstring>

#define INF 10000

using namespace std;

int stone[10000] = {0,};
int DP[10000][150];

int main(){
    int N, M, idx, temp;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>idx;
        stone[idx-1] = -1;
    }
    memset(DP, 0x11, sizeof(DP));
    DP[0][0] = 0;
    for(int i=1;i<N;i++){
        if(stone[i] == -1) continue;
        for(int x=1;x<=i&&x<149;x++){
            temp = min(DP[i-x][x], min(DP[i-x][x-1], DP[i-x][x+1]));
            if(temp >= 10000) continue;
            DP[i][x] = temp + 1;
        }
    }

    int answer = INF;
    for(int i=1;i<150;i++){
        answer = min(answer ,DP[N-1][i]);
    }
    if(answer == INF) cout<<"-1\n";
    else cout<<answer<<"\n";
}