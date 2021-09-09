#include <string>
#include <vector>
#include <queue>

#define DOWN 0
#define RIGHT 1

using namespace std;

int N;
vector<vector<int>> Board;

typedef struct Data{
    int x, y, d;
}Data;

bool check(Data data){
    int x, y, d;
    x = data.x;
    y = data.y;
    d = data.d;
    if(x < 0 || y < 0 || x >= N || y >= N) return false;
    if(Board[y][x] == 1) return false;
    if(d == DOWN){
        if(y+1 >= N) return false;
        if(Board[y+1][x] == 1) return false;
    }
    else if(d == RIGHT){
        if(x+1 >= N) return false;
        if(Board[y][x+1] == 1) return false;
    }
    return true;
}

int visit[100][100][2] = {0,};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int down_dx[] = {-1, -1, 0, 0};
int down_dy[] = {0, 1, 0, 1};
int down_check_dx[] = {-1, -1, 1, 1};
int down_check_dy[] = {1, 0, 1, 0};

int right_dx[] = {1, 1, 0, 0};
int right_dy[] = {-1, 0, 0, -1};
int right_check_dx[] = {0, 0, 1, 1};
int right_check_dy[] = {-1, 1, 1, -1};

int bfs(){
    queue<Data> q;
    Data data, curr;
    int check_x, check_y;
    data.x = 0;
    data.y = 0;
    data.d = RIGHT;
    q.push(data);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr.x == N-1 && curr.y == N-2 && curr.d == DOWN) return visit[curr.y][curr.x][curr.d];
        else if(curr.x == N-2 && curr.y == N-1 && curr.d == RIGHT) return visit[curr.y][curr.x][curr.d];
        
        for(int i=0;i<4;i++){
            data.x = curr.x + dx[i];
            data.y = curr.y + dy[i];
            data.d = curr.d;
            if(check(data) && visit[data.y][data.x][data.d] == 0){
                visit[data.y][data.x][data.d] = visit[curr.y][curr.x][curr.d] + 1;
                q.push(data);
            }
        }
        if(curr.d == DOWN){
            for(int i=0;i<4;i++){
                data.x = curr.x + down_dx[i];
                data.y = curr.y + down_dy[i];
                data.d = RIGHT;
                check_x = curr.x + down_check_dx[i];
                check_y = curr.y + down_check_dy[i];
                if(check(data) && Board[check_y][check_x] == 0 && visit[data.y][data.x][data.d] == 0){
                    visit[data.y][data.x][data.d] = visit[curr.y][curr.x][curr.d] + 1;
                    q.push(data);
                }
            }
        }
        else{
            for(int i=0;i<4;i++){
                data.x = curr.x + right_dx[i];
                data.y = curr.y + right_dy[i];
                data.d = DOWN;
                check_x = curr.x + right_check_dx[i];
                check_y = curr.y + right_check_dy[i];
                if(check(data) && Board[check_y][check_x] == 0 && visit[data.y][data.x][data.d] == 0){
                    visit[data.y][data.x][data.d] = visit[curr.y][curr.x][curr.d] + 1;
                    q.push(data);
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    Board = board;
    N = board.size();
    answer = bfs();
    return answer;
}