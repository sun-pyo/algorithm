#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<string> map;
int visit[100][100];

void dfs(int start_x, int start_y, int N){
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(start_x, start_y));
    while(!stack.empty()){
        pair<int, int> xy = stack.back();
        int x = xy.first;
        int y = xy.second;
        stack.pop_back();
        if(visit[y][x] == 0){
            visit[y][x] = 1;
            if(x-1 >= 0 && visit[y][x-1] == 0 && map[y][x] == map[y][x-1]){
                stack.push_back(make_pair(x-1, y));
            }
            if(x+1 < N && visit[y][x+1] == 0 && map[y][x] == map[y][x+1]){
                stack.push_back(make_pair(x+1, y));
            }    
            if(y-1 >= 0 && visit[y-1][x] == 0 && map[y][x] == map[y-1][x]){
                stack.push_back(make_pair(x, y-1));
            }
            if(y+1 < N && visit[y+1][x] == 0 && map[y][x] == map[y+1][x]){
                stack.push_back(make_pair(x, y+1));
            }   
        }
    }
}

int main(){
    int N;
    string s;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        cin>>s;
        map.push_back(s);
    }
    int count_ori = 0, count_rg = 0;
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j] == 0){
                dfs(j, i, N);
                count_ori++;
            }
        }
    }
    for(int i = 0;i<N;i++){
        memset(visit[i], 0, sizeof(int)*N);
        for(int j = 0;j<N;j++){
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j] == 0){
                dfs(j, i, N);
                count_rg++;
            }
        }
    }
    printf("%d %d", count_ori, count_rg);


    
}