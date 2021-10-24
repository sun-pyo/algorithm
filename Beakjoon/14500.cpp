#include <iostream>
#include <vector>

using namespace std;

int map[500][500];
int visit[500][500] = {0,};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int points_x[4][3] = {{1, 1, 1},
                    {1, 1, 2},
                    {0, 0, 1},
                    {1, 1, 2}};
int points_y[4][3] = {{0, -1, 1},
                    {0, -1, 0},
                    {1, 2, 1},
                    {0, 1, 0}};
int N, M;

int dfs(int x, int y, int depth, int sum){
    if(depth == 3) return sum;
    int next_x, next_y, res = 0;
    visit[y][x] = 1;
    for(int i=0;i<4;i++){
        next_x = x + dx[i];
        next_y = y + dy[i];
        if(next_x >= 0 && next_y >= 0 && next_y < N && next_x < M && visit[next_y][next_x] == 0){
            res = max(res, dfs(next_x, next_y, depth+1, sum + map[next_y][next_x]));
        }
    }
    visit[y][x] = 0;
    return res;
}

int last_shape(int x, int y){
    int res = 0, sum, next_x, next_y;
    for(int i=0;i<4;i++){
        sum = map[y][x];
        for(int j=0;j<3;j++){
            next_x = x + points_x[i][j];
            next_y = y + points_y[i][j]; 
            if(next_x >= 0 && next_y >= 0 && next_y < N && next_x < M)
                sum += map[next_y][next_x]; 
        }
        res = max(res, sum);
    }
    return res;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            answer = max(answer, dfs(j, i, 0, map[i][j]));
            answer = max(answer, last_shape(j, i));
        }
    }
    cout<<answer<<"\n";
}