#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
queue<pair<int, int>> q;
int M, N;

int check_all(){
    int res = -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0) return 0;
            else res = max(res, map[i][j]); 
        }
    }
    return res;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(){
    while(!q.empty()){
        pair<int, int> xy = q.front();
        q.pop();
        int x = xy.first;
        int y = xy.second; 

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >=0 && new_x < M && new_y >=0 && new_y <N && map[new_y][new_x] == 0){
                map[new_y][new_x] = map[y][x] + 1;
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main(){
    scanf("%d %d", &M, &N);
    map.resize(N+1);
    for(int i=0;i<N;i++){
        map[i].resize(M+1);
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1)
                q.push(make_pair(j, i));
        }
    }

    int answer = check_all();
    if(answer != 0)
        printf("%d", 0);
    else{
        bfs(); 
        printf("%d", check_all()-1);
    }
}