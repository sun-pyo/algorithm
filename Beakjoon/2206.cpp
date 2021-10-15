#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>

#define INF 2000000000

using namespace std;

int map[1000][1000] = {0,};
int visit[1000][1000][2] = {0,};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;

int bfs(int start_x, int start_y){
    memset(visit, 0, sizeof(visit));
    queue<pair<int ,pair<int, int>>> q;
    q.push({0, {start_x, start_y}});
    visit[start_y][start_x][0] = 1;
    int x, y, next_x, next_y, break_wall;
    while(!q.empty()){
        break_wall = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        if(x == M-1 && y == N-1) return visit[y][x][break_wall];
        for(int i=0;i<4;i++){
            next_x = x + dx[i];
            next_y = y + dy[i];
            if(next_x >= 0 && next_x < M && next_y >=0 && next_y < N && visit[next_y][next_x][break_wall] == 0){
                if(map[next_y][next_x] == 0){
                    visit[next_y][next_x][break_wall] = visit[y][x][break_wall] + 1;
                    q.push({break_wall, {next_x, next_y}});
                }
                else if(break_wall == 0 && map[next_y][next_x] == 1) 
                {
                    visit[next_y][next_x][1] = visit[y][x][break_wall] + 1;
                    q.push({1, {next_x, next_y}});
                }
            }
        }
    }
    return INF;
}

int main(){
    string s;
    vector<pair<int ,int>> one;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            map[i][j] = s[j] - '0';
        }
    }    
    int x, y, answer, size;
    answer = bfs(0, 0);
    size = one.size();
    if(answer == INF) answer = -1;
    cout<<answer<<"\n";
}