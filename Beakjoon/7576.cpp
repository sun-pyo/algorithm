#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
queue<pair<int, int>> parent;
int M, N;

void clear(queue<pair<int, int>> &q){
    while(!q.empty()) q.pop();
}

bool check_all(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}


int solution(){
    queue<pair<int,int>> child;
    int answer = 0;

    while(!parent.empty()){
        while(!parent.empty()){
            pair<int, int> xy = parent.front();
            parent.pop();
            int x = xy.first;
            int y = xy.second; 
            if(x-1 >=0 && map[y][x-1] == 0){
                map[y][x-1] = 1;
                child.push(make_pair(x-1, y));
            }
            if(x+1 < M && map[y][x+1] == 0){
                map[y][x+1] = 1;
                child.push(make_pair(x+1, y));
            }
            if(y-1 >= 0 && map[y-1][x] == 0){
                map[y-1][x] = 1;
                child.push(make_pair(x, y-1));
            }
            if(y+1 < N && map[y+1][x] == 0){
                map[y+1][x] = 1;
                child.push(make_pair(x, y+1));
            }
        }
        parent = child;
        if(child.empty()) break;
        clear(child);
        answer++;
    }
    
    if(check_all())
        return answer;
    else
        return -1;
}

int main(){
    scanf("%d %d", &M, &N);
    map.resize(N+1);
    for(int i=0;i<N;i++){
        map[i].resize(M+1);
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1)
                parent.push(make_pair(j, i));
        }
    }
    if(check_all())
        printf("%d", 0);
    else 
        printf("%d", solution());

}