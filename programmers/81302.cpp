#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int start_x, int start_y, vector<string> map){
    vector<vector<int>> visit;
    visit.resize(5);
    for(int i=0;i<5;i++){
        visit[i].resize(5);
        for(int j=0;j<5;j++) visit[i][j] = -1;
    }
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visit[start_y][start_x] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visit[y][x] > 2) return 1;
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5 && map[next_y][next_x] != 'X' && visit[next_y][next_x] == -1){
                if(map[next_y][next_x] == 'P' && visit[y][x] <= 1){
                    return 0;
                }
                else {
                    visit[next_y][next_x] = visit[y][x] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++){
        bool succ = true;
        for(int j=0;((j<places[i].size())&&succ);j++){
            for(int k=0;((k<places[i][j].size())&&succ);k++){
                if(places[i][j][k] == 'P'){
                    if(bfs(k, j, places[i]) == 0) succ=false;
                }    
            }
        }
        if(succ) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}