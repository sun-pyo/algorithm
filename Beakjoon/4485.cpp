#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t = 0;
    while(true){
        t++;
        cin>>N;
        if(N==0) break;
        vector<vector<int>> map;
        vector<vector<int>> dist;
        vector<vector<int>> visit;

        map.resize(N);
        dist.resize(N);
        visit.resize(N);
        for(int i=0;i<N;i++){
            map[i].resize(N);
            dist[i].resize(N);
            visit[i].resize(N);
            for(int j=0;j<N;j++){
                cin>>map[i][j];
                visit[i][j] = 0;
                dist[i][j] = INF;
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        dist[0][0] = map[0][0];
        pq.push(make_pair(-dist[0][0], make_pair(0, 0)));
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();
            
            if(visit[y][x] == 1) continue;
            visit[y][x] = 1;
            for(int i=0;i<4;i++){
                int next_x = X[i] + x;
                int next_y = Y[i] + y;
                if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && visit[next_y][next_x] == 0){
                    if(dist[next_y][next_x] > dist[y][x] + map[next_y][next_x] )
                    {
                        dist[next_y][next_x] = dist[y][x] + map[next_y][next_x];
                        pq.push(make_pair(-dist[next_y][next_x], make_pair(next_x, next_y)));
                    }
                }
            }
        }

        cout<<"Problem "<<t<<": "<<dist[N-1][N-1]<<"\n";
    }
}