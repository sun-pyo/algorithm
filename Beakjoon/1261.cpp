#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;

vector<string> maze;
vector<vector<int>> dist;
vector<vector<int>> visit;

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

void dijkstra(){
    int x = 0;
    int y = 0;
    priority_queue<pair<int,pair<int,int>>> pq;
    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(x,y)));
    while(!pq.empty()){
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();

        if(visit[y][x] == 1) continue;
        visit[y][x] = 1;
        for(int i=0;i<4;i++){
            int next_x = x + X[i];
            int next_y = y + Y[i];
            if(next_x >=0 && next_x <maze[0].size() && next_y >=0 && next_y < maze.size() && visit[next_y][next_x] == 0){
                if(maze[next_y][next_x] == '1' && dist[next_y][next_x] > dist[y][x] + 1){
                    dist[next_y][next_x] = dist[y][x] + 1;
                    pq.push(make_pair(-dist[next_y][next_x], make_pair(next_x, next_y)));
                }   
                else if(maze[next_y][next_x] == '0' && dist[next_y][next_x] > dist[y][x]){
                    dist[next_y][next_x] = dist[y][x];
                    pq.push(make_pair(-dist[next_y][next_x], make_pair(next_x, next_y)));
                }
            }
        }
        
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int M, N;
    cin>>M>>N;
    maze.resize(N);
    dist.resize(N);
    visit.resize(N);
    
    for(int i=0;i<N;i++){
        dist[i].resize(M);
        visit[i].resize(M);
        cin>>maze[i];
        for(int j=0;j<M;j++){
            dist[i][j] = INF;
        }
    }
    dijkstra();
    cout<<dist[N-1][M-1];
}