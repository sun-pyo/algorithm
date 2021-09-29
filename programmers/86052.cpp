#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


using namespace std;

int visit[500][500][4] = {0,};
int y_max, x_max;
vector<string> Grid;

int get_dir(int x, int y, int d){
    if(Grid[y][x] == 'S') return d;
    else if(Grid[y][x] == 'L'){
        if(d == UP) return LEFT;
        else if(d == DOWN) return RIGHT;
        else if(d == LEFT) return DOWN;
        else if(d == RIGHT) return UP;
    }
    else if(Grid[y][x] == 'R'){
        if(d == UP) return RIGHT;
        else if(d == DOWN) return LEFT;
        else if(d == LEFT) return UP;
        else if(d == RIGHT) return DOWN;
    }
}

vector<int> get_next(vector<int> curr){
    int x, y, d, next_x, next_y, next_d;
    x = curr[0];
    y = curr[1];
    d = curr[2];
    next_y = y;
    next_x = x;
    // 상
    if(d == UP){
        next_y--;
        if(next_y < 0) next_y = y_max-1;
    }
    // 하
    else if(d == DOWN){
        next_y++;
        if(next_y >= y_max) next_y = 0;
    }
    // 좌
    else if(d == LEFT){
        next_x--;
        if(next_x < 0) next_x = x_max-1;
    }
    // 우
    else{
        next_x++;
        if(next_x >= x_max) next_x = 0;
    }
    next_d = get_dir(next_x, next_y, d);
    return {next_x, next_y, next_d};
}

int sol(int start_x, int start_y, int start_d){
    int length = 0;
    vector<vector<int>> st;
    st.push_back({start_x, start_y, start_d});
    int x, y, d;
    while(!st.empty()){
        x = st.back()[0];
        y = st.back()[1];
        d = st.back()[2];
        st.pop_back();
        if(visit[y][x][d] == 1) break;
        length++;
        visit[y][x][d] = 1;
        st.push_back(get_next({x, y, d}));
    }
    return length;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    Grid = grid;
    y_max = grid.size();
    x_max = grid[0].size();
    for(int y=0;y<grid.size();y++){
        for(int x=0;x<grid[y].size();x++){
            for(int d=0;d<4;d++){
                if(visit[y][x][d] == 0){
                    answer.push_back(sol(x, y, d));
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<int> ans = solution({"SL", "LR"});
    for(int num : ans){
        cout<<num<<"\n";
    }
}