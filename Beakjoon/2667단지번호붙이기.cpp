#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string map[25];
int visit[25][25];

int dfs(int start_x, int start_y){
    vector<pair<int,int>> stack;
    stack.push_back(make_pair(start_x, start_y));
    int count = 0;
    while(!stack.empty()){
        pair<int, int> xy = stack.back();
        int x = xy.first;
        int y = xy.second;
        stack.pop_back();
        if(visit[y][x] == 0){
            count++;
            visit[y][x] = -1;
            if( x-1 >= 0 && visit[y][x-1] == 0 && map[y][x-1] == '1' )
            {
                stack.push_back(make_pair(x-1, y));
            }
            if( x+1 < 25 && visit[y][x+1] == 0 && map[y][x+1] == '1'){
                stack.push_back(make_pair(x+1, y));
            }
            if( y-1 >= 0 && visit[y-1][x] == 0 && map[y-1][x] == '1'){
                stack.push_back(make_pair(x, y-1));
            }
            if( y+1 < 25 && visit[y+1][x] == 0 && map[y+1][x] == '1'){
                stack.push_back(make_pair(x, y+1));
            }
        }
    }
    return count;
}

int main(){
    int N;
    scanf("%d",&N);
    vector<pair<int, int>> node;
    for(int i = 0;i<N;i++){
        cin>>map[i];
        for(int j=0;j<N;j++){
            if(map[i][j] == '0') 
                visit[i][j] = -1;
            else 
                node.push_back(make_pair(j ,i));
        }

    }

    vector<int> answer;
    for(int i=0;i<node.size();i++){
        int x = node[i].first;
        int y = node[i].second;
        if(visit[y][x] == 0){
            answer.push_back(dfs(x,y));
        }
    }

    sort(answer.begin(), answer.end());

    printf("%d\n",answer.size());
    for(int i = 0;i<answer.size();i++){
        printf("%d\n", answer[i]);
    }

}