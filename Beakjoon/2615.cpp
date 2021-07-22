#include <iostream>
#include <vector>

using namespace std;

int board[19][19] = {0,};

pair<int, int> find_left(int x, int y, int add_x, int add_y){
    int left_x = x;
    int left_y = y;
    while(left_x>=0&&left_y>=0){
        if(board[y][x] != board[left_y][left_x]) break;
        left_x -= add_x;
        left_y -= add_y;
    }
    left_x += add_x;
    left_y += add_y;
    
    return {left_x, left_y};
}

pair<int, int> check(int x, int y, int add_x, int add_y){
    pair<int, int> left = find_left(x,y,add_x,add_y);
    int next_x = left.first, next_y = left.second, cnt = 0;
    while(next_x<19&&next_y<19&&cnt<6){
        if(board[y][x] != board[next_y][next_x]) break;
        cnt++;
        next_x += add_x;
        next_y += add_y;
    }
    if(cnt == 5) return {left.first+1, left.second+1};
    else return {-1, -1};
}

pair<int, int> all_check(int x, int y){
    pair<int, int> res;
    int add_x[] = {1, 0, 1, 1};
    int add_y[] = {0, 1, 1, -1};
    for(int i=0;i<4;i++){
        res = check(x, y, add_x[i], add_y[i]);
        if(res.first != -1) return res;
    }
    return res;
}

int main(){
    pair<int, int> x_y;
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(board[i][j] != 0){
                x_y = all_check(j, i);
                if(x_y.first != -1){
                    cout<<board[i][j]<<"\n"<<x_y.second<<" "<<x_y.first;
                    return 0;
                }
            }
        }
    }
    cout<<"0\n";

}