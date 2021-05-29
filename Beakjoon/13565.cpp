#include <queue>
#include <iostream>
#include <vector>

using namespace std;

vector<string> map;
vector<vector<int>> visit;

int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};
int M, N;

void bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visit[y][x] == 1) continue;
        visit[y][x] = 1;
        
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && map[next_y][next_x] == '0' && visit[next_y][next_x] != 1){
                q.push({next_x, next_y});
            }
        }
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin>>M>>N;
    map.resize(M);
    visit.resize(M);

    for(int i=0;i<M;i++){
        visit[i].resize(N);
        for(int j=0;j<N;j++) visit[i][j] = 0;
        cin>>map[i];
    }

    for(int i=0;i<N;i++){
        bfs(i, 0);
    }

    for(int i=0;i<N;i++){
        if(visit[M-1][i] == 1){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}