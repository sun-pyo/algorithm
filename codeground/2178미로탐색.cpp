#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
int visited[101][101];
int count[101][101];
int N, M;

queue< pair <int, int> > q;
void solution(){
    int x,y;
    pair<int, int> yx = make_pair(1,1);
    q.push(yx);
    while(!q.empty()){
        yx = q.front();
        q.pop();
        y = yx.first;
        x = yx.second;
        if(visited[y][x] == 0){
            visited[y][x] = 1;
            if(x>0 && x<M && y>0 && y<=N && visited[y][x+1] == 0 && map[y][x+1-1] == '1'){
                count[y][x+1] = count[y][x] + 1;
                pair<int, int> new_yx = make_pair(y, x+1);
                q.push(new_yx);
            }
            if(x>1 && x<=M && y>0 && y<=N && visited[y][x-1] == 0 && map[y][x-1-1] == '1'){
                count[y][x-1] = count[y][x] + 1;
                pair<int, int> new_yx = make_pair(y, x-1);
                q.push(new_yx);
            }
            if(x>0 && x<=M && y>0 && y<N && visited[y+1][x] == 0 && map[y+1][x-1] == '1'){
                count[y+1][x] = count[y][x] + 1;
                pair<int, int> new_yx = make_pair(y+1, x);
                q.push(new_yx);
            }
            if(x>0 && x<M && y>1 && y<=N && visited[y-1][x] == 0 && map[y-1][x-1] == '1'){
                count[y-1][x] = count[y][x] + 1;
                pair<int, int> new_yx = make_pair(y-1, x);
                q.push(new_yx);
            }
        }
    }
    return;
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>map[i];
    }


    solution();
    printf("%d", count[N][M]+1);

}