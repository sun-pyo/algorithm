#include <vector>
#include <iostream>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int map[20][20] = {0,};
int like[401][4];

int main(){
    int N;
    cin>>N;

    int std, like_cnt, max_like, empty_cnt, max_empty, pos_x, pos_y, x, y;
    for(int n=0;n<N*N;n++){
        cin>>std;
        for(int j=0;j<4;j++){
            cin>>like[std][j];
        }

        max_like = -1;
        max_empty = -1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                empty_cnt = 0;
                like_cnt = 0;
                for(int k=0;k<4;k++){
                    x = j + dx[k];
                    y = i + dy[k];
                    if(x >= 0 && y >= 0 && x < N && y < N){
                        if(map[y][x] == 0) empty_cnt++;
                        else if(map[y][x]==like[std][0] || map[y][x]==like[std][1] || map[y][x] == like[std][2] || map[y][x]==like[std][3]) like_cnt++;
                    }
                }
                if(map[i][j] == 0){
                    if(max_like < like_cnt || (max_like == like_cnt && max_empty < empty_cnt)){
                        pos_x = j;
                        pos_y = i;
                        max_like = like_cnt;
                        max_empty = empty_cnt;
                    }
                }
            }
        }
        map[pos_y][pos_x] = std;
    }



    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std = map[i][j];
            like_cnt = 0;
            for(int k=0;k<4;k++){
                x = j + dx[k];
                y = i + dy[k];
                if(x >= 0 && y >= 0 && x < N && y < N){
                    if(map[y][x]==like[std][0] || map[y][x]==like[std][1] || map[y][x] == like[std][2] || map[y][x]==like[std][3]) like_cnt++;
                }
            }
            if(like_cnt == 1) answer += 1;
            else if(like_cnt == 2) answer += 10;
            else if(like_cnt == 3) answer += 100;
            else if(like_cnt == 4) answer += 1000;
        }
    }
    cout<<answer;
}