#include <iostream>
#include <vector>
#include <cstring>

#define INF 100001

using namespace std;

int i;

int DP[1000][16][16], Black[1000], White[1000];
int dfs(int idx, int black, int white){
    if(black == 15 && white == 15) return 0;
    if(black > 15 || white > 15 || idx >= i) return -INF;
    if(DP[idx][black][white] != -1) return DP[idx][black][white];
    DP[idx][black][white] = dfs(idx+1, black, white);
    DP[idx][black][white] = max(DP[idx][black][white], dfs(idx+1, black+1, white) + Black[idx]);
    DP[idx][black][white] = max(DP[idx][black][white], dfs(idx+1, black, white+1) + White[idx]);
    return DP[idx][black][white];
}

int main(){
    int b, w;
    i = 0;
    memset(DP, -1, sizeof(DP));
    while(cin>>w>>b){
        Black[i] = b;
        White[i] = w;
        i++;
    }
    cout<<dfs(0, 0, 0);
}