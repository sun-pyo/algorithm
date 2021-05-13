#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> map;
    int N;
    cin>>N;
    map.resize(N);
    for(int i=0;i<N;i++){
        map[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    int x, y, right, down;
    queue<pair<int, int>> q;
    bool visit[64][64] = {false, };
    q.push(make_pair(0, 0));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x == N-1 && y == N-1) {
            cout<<"HaruHaru\n";
            return 0;
        }
        if(visit[y][x]) continue;
        if(map[y][x] == 0) continue;
        visit[y][x] = true;
        right = map[y][x] + x;
        down = map[y][x] + y; 
        if(right >= 0 && right < N){
            q.push(make_pair(right, y));
        }
        if(down >= 0 && down < N){
            q.push(make_pair(x, down));
        }
    }
    cout<<"Hing\n";
    return 0;
}