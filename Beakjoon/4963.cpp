#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int visit[50][50];
vector<vector<int>> map;

void dfs(int start_x, int start_y, int w, int h){
    vector<pair<int,int>> stack;
    stack.push_back(make_pair(start_x, start_y));
    while(!stack.empty()){
        pair<int,int> cur = stack.back();
        stack.pop_back();
        int cur_x = cur.first;
        int cur_y = cur.second;
        if(visit[cur_y][cur_x] == 0){
            visit[cur_y][cur_x] = 1;
            
            // 상단
            if(cur_y-1 >= 0 && visit[cur_y-1][cur_x] == 0){
                stack.push_back(make_pair(cur_x, cur_y-1));
            }
            // 하단
            if(cur_y+1 < h && visit[cur_y+1][cur_x] == 0){
                stack.push_back(make_pair(cur_x, cur_y+1));
            }
            // 좌측
            if(cur_x-1 >= 0 && visit[cur_y][cur_x-1] == 0){
                stack.push_back(make_pair(cur_x-1, cur_y));
            }
            //우측
            if(cur_x+1 < w && visit[cur_y][cur_x+1] == 0){
                stack.push_back(make_pair(cur_x+1, cur_y));
            }

            // 좌측상단
            if(cur_y-1 >= 0 && cur_x-1 >= 0 && visit[cur_y-1][cur_x-1] == 0){
                stack.push_back(make_pair(cur_x-1, cur_y-1));
            }
            // 좌측하단
            if(cur_y+1 < h && cur_x-1 >= 0 && visit[cur_y+1][cur_x-1] == 0){
                stack.push_back(make_pair(cur_x-1, cur_y+1));
            }
            // 우측상단
            if(cur_y-1 >= 0 && cur_x+1 < w && visit[cur_y-1][cur_x+1] == 0){
                stack.push_back(make_pair(cur_x+1, cur_y-1));
            }
            // 우측하단
            if(cur_y+1 < h && cur_x+1 < w && visit[cur_y+1][cur_x+1] == 0){
                stack.push_back(make_pair(cur_x+1, cur_y+1));
            }
        }
    }
}

int main(){
    vector<vector<int>> map;
    int w, h;
    vector<int> answer;
    while(1){
        scanf("%d %d", &w, &h);
        if(w==0 && h==0){
            break;
        }

        map.resize(h+1);
        
        for(int i = 0;i<h;i++)
            memset(visit[i], 1, sizeof(int)*w);

        for(int i=0;i<h;i++){
            map[i].resize(w+1);
            for(int j=0;j<w;j++){
                scanf("%d ", &map[i][j]);
                if(map[i][j] == 1)
                    visit[i][j] = 0;
            }
        }

        int answer_temp = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(visit[i][j] == 0){
                    answer_temp++;
                    dfs(j, i, w, h);
                }
            }
        }
        answer.push_back(answer_temp);
        map.clear();
    }
    for(int i=0;i<answer.size();i++){
        printf("%d\n", answer[i]);
    }

}