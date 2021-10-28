#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> map;
int visit[4][4] = {0,};
int N, M, answer=-1;

void solution(int idx, int sum){
    int x = idx%M;
    int y = idx/M;
    if(idx == N*M-1){
        if(visit[y][x] == 0) sum += map[y][x] - '0';
        answer = max(answer, sum);
        return;
    }
    string s_num;
    bool check;
    if(visit[y][x] == 0){
        for(int i=0;x+i<M;i++){
            s_num = "";
            check = true;
            for(int j=0;j<=i;j++){
                if(visit[y][x+j] == 1){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            for(int j=0;j<=i;j++){
                s_num += map[y][x+j];
                visit[y][x+j] = 1;  
            }

            solution(idx+1, sum + stoi(s_num));
            for(int j=0;j<=i;j++){
                visit[y][x+j] = 0;  
            }
        }

        for(int i=0;y+i<N;i++){
            s_num = "";
            check = true;
            for(int j=0;j<=i;j++){
                if(visit[y+j][x] == 1){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            for(int j=0;j<=i;j++){
                s_num += map[y+j][x];
                visit[y+j][x] = 1;  
            }
            solution(idx+1, sum + stoi(s_num));
            for(int j=0;j<=i;j++){
                visit[y+j][x] = 0;  
            }
        }
    }
    else solution(idx+1, sum);
}

int main(){
    string s, temp;
    cin>>N>>M;
    map.resize(N);
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    solution(0, 0);
    cout<<answer<<"\n";
}