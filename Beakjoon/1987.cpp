#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> board;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int visit[26] = {0,};

int solution(int x, int y){
    int idx = board[y][x] - 'A';
    if(visit[idx] == 1) return 0;
    visit[idx] = 1;
    int next_x, next_y, res = 0;
    
    for(int i=0;i<4;i++){
        next_x = x + dx[i];
        next_y = y + dy[i];
        if(next_x >= 0 && next_x < board[y].size() && next_y >=0 && next_y < board.size()){
            res = max(res, solution(next_x, next_y)); 
        }
    }
    visit[idx] = 0;
    return res + 1;
}

int main(){
    int R, C;
    cin>>R>>C;
    board.resize(R);
    for(int i=0;i<R;i++){
        cin>>board[i];
    }
    int answer = solution(0, 0);
    cout<<answer<<"\n";
}