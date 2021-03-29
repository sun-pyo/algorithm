#include<vector>
#include <queue>
using namespace std;

int visit[100][100] = {0,};

int BFS(vector<vector<int>> &maps)
{
    int X[] = {1,-1,0,0};
    int Y[] = {0, 0, 1, -1};
    queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    visit[0][0] = 1;
    int n = maps.size();
    int m = maps[0].size();
    while(!pq.empty()){
        pair<int,int> xy = pq.front();
        int x = xy.first;
        int y = xy.second;
        if(x == m-1 && y == n-1) return visit[n-1][m-1];
        pq.pop();
        
        for(int i=0;i<4;i++){
            int next_x = x + X[i];
            int next_y = y + Y[i];
            if(next_x >= 0 && next_x <m && next_y >= 0 && next_y < n && visit[next_y][next_x] == 0 && maps[next_y][next_x] == 1){
                visit[next_y][next_x] = visit[y][x] + 1;
                pq.push(make_pair(next_x, next_y));
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = BFS(maps);
    return answer;
}