#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long DP[32][32][3];
int board[32][32] = {0,};
int N;
vector<int> horizontal_d = {0, 2};
vector<int> vertical_d = {1, 2};
vector<int> diagonal_d = {0, 1, 2};

bool check_point(int x, int y, int d){
    if (x >= N || y >= N || board[y][x] == 1) return false;
    if (d == 0){
        if (x+1 >= N || board[y][x+1] == 1) return false;
    }
    else if(d == 1){
        if(y+1 >= N || board[y+1][x] == 1) return false;
    }
    else if(d == 2){ 
        if (x+1 >= N || y+1 >=N || board[y+1][x] == 1 || board[y][x+1] == 1 || board[y+1][x+1] == 1) return false;
    }
    return true;
}

long long dfs(int x, int y, int d){
    if (x >= N || y >= N) return 0;
    if (d == 0 && x == N-2 && y == N-1) return 1;
    else if (d == 1 && y == N-2 && x == N-1) return 1;
    else if (d == 2 && y == N-2 && x == N-2) return 1;
    
    if(DP[y][x][d] != -1)
        return DP[y][x][d];

    DP[y][x][d] = 0;
    if (d == 0){
        for(int next_d : horizontal_d){
            if(check_point(x+1, y, next_d))
                DP[y][x][d] += dfs(x+1, y, next_d);
        }
    }
    else if(d == 1){
        for(int next_d : vertical_d){
            if(check_point(x, y+1, next_d))
                DP[y][x][d] += dfs(x, y+1, next_d);
        }
    }
    else if(d == 2){
        for (int next_d : diagonal_d){
            if(check_point(x+1, y+1, next_d))
                DP[y][x][d] += dfs(x+1, y+1, next_d);
        }
    }
    return DP[y][x][d];
}

int main(){
    memset(DP, -1, sizeof(DP));
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }

    cout<<dfs(0, 0, 0);

}