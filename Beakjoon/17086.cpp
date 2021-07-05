#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
int N, M;

int bfs(int start_x, int start_y){
    int visit[50][50] = {0,};
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(map[y][x] == 1) return visit[y][x];
        for(int i=0;i<8;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x >=0 && next_x < M && next_y >= 0 && next_y < N && visit[next_y][next_x] == 0){
                visit[next_y][next_x] = visit[y][x] + 1; 
                q.push({next_x, next_y});
            }
        }
    }
    return 0;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    int res, answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            res = bfs(j, i);
            if(res > answer) answer = res;
        }
    }
    cout<<answer;
}