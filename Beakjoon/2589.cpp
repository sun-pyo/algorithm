#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<vector<int>> map;

int x_[] = {1, -1, 0, 0};
int y_[] = {0, 0, 1, -1};

int bfs(int start_y, int start_x){
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    pair<int, int> xy;
    int max_ = 0;
    map[start_y][start_x] = 1;
    while(!q.empty()){
        xy = q.front();
        q.pop();
        int x = xy.first;
        int y = xy.second;
        if(max_ < map[y][x]) max_ = map[y][x];
        for(int i=0;i<4;i++){
            int curr_x = x_[i] + x;
            int curr_y = y_[i] + y;
            if(0 <= curr_x && curr_x < map[0].size() && 0<=curr_y && curr_y < map.size() && map[curr_y][curr_x] == 0 ){
                map[curr_y][curr_x] =  map[y][x] + 1;
                q.push(make_pair(curr_x, curr_y));
            } 
        }
    }
    return max_;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
    char c;
    cin>>h>>w;
    map.resize(h);
    for(int i=0;i<h;i++){
        map[i].resize(w);
        for(int j=0;j<w;j++){
            cin>>c;
            if(c == 'L'){
                map[i][j] = 0;
            }
            else{
                map[i][j] = -1;
            }
        }
    }
    vector<vector<int>> map_temp = map;
    vector<pair<int, int>> end_point;
    int answer = 0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j] == 0){
                int res = bfs(i, j);
                if(answer < res) answer = res;
                map = map_temp;
            }
        }
    }
    
    cout<<answer-1<<"\n";
}