#include <iostream>
#include <vector>
#include <cstring>

#define UP 0
#define RIGHT 1

using namespace std;

int map[101][101][2] = {0,};
long long DP[101][101] = {0,};
int N, M;

long long dfs(int x, int y){
    if(x == N && y == M) return 1;
    if(DP[y][x] != -1) return DP[y][x];
    long long res = 0;
    if(y+1 <= M && map[y][x][UP] == 0){
        res += dfs(x, y+1);
    }
    if(x+1 <= N && map[y][x][RIGHT] == 0){
        res += dfs(x+1, y);
    }
    DP[y][x] = res;
    return DP[y][x];
}


int main(){
    int K, a, b, c, d;
    cin>>N>>M;
    cin>>K;
    memset(DP, -1, sizeof(DP));
    for(int k=0;k<K;k++){
        cin>>a>>b>>c>>d;
        if(a == c){
            if(b > d){
                map[d][c][UP] = 1;
            }else{
                map[b][a][UP] = 1;
            }
        }
        else if(b == d){
            if(a > c){
                map[d][c][RIGHT] = 1;
            }else{
                map[b][a][RIGHT] = 1;
            }
        }
    }
    cout<<dfs(0, 0)<<"\n";
}