#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int map[50][50];
int visit[50][50];

void dfs(int start_x, int start_y){
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(start_x, start_y));
    int x,y;
    while(!stack.empty()){
        pair<int,int> curr = stack.back();
        x = curr.first;
        y = curr.second;
        visit[y][x] = 1;      
        stack.pop_back();
        if(x-1 >= 0 && visit[y][x-1] == 0 && map[y][x-1] == 1 ){
            stack.push_back(make_pair(x-1, y));
        }
        if(x+1 < 50 &&  visit[y][x+1] == 0 && map[y][x+1] == 1){
            stack.push_back(make_pair(x+1, y));
        }
        if(y-1 >= 0 && visit[y-1][x] == 0 && map[y-1][x] == 1 ){
            stack.push_back(make_pair(x, y-1));
        }
        if(y+1 < 50 &&  visit[y+1][x] == 0 && map[y+1][x] == 1){
            stack.push_back(make_pair(x, y+1));
        }
    }
}

int main(){
    int T, M, N, K, x, y;
    
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        for(int i = 0;i<50;i++){
            memset(map[i], 0, sizeof(int)*50);
            memset(visit[i], 1, sizeof(int)*50);
        }
        scanf("%d %d %d",&M, &N, &K);
        for(int k = 0;k<K;k++){
            scanf("%d %d", &x, &y);
            visit[y][x] = 0;
            map[y][x] = 1;
        }

        int count = 0;
        for(int i = 0;i<N;i++){
            for(int j=0;j<M;j++){
                if(visit[i][j] == 0) {
                    dfs(j, i);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }



}