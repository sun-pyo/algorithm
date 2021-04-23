#include <string>
#include <iostream>
using namespace std;

struct Node{
    int dir[4] = {0,};
};

int solution(string dirs) {
    int answer = 0;
    Node node[11][11];
    int x = 5, y = 5;
    for(int i=0;i<dirs.size();i++){
        cout<<"x, y = "<<x<<" "<<y<<" "<<answer<<"\n";
        if(dirs[i] == 'U'){
            if(y<10){
                if(node[y][x].dir[0] == 0){
                    node[y][x].dir[0] = 1;
                    node[y+1][x].dir[1] = 1;
                    answer++;
                }
                y++;
            }
        }
        else if(dirs[i] == 'D'){
            if(y > 0){
                if(node[y][x].dir[1] == 0){
                    node[y][x].dir[1] = 1;
                    node[y-1][x].dir[0] = 1;
                    answer++;
                }
                y--;
            }
        }
        else if(dirs[i] == 'R'){
            if(x < 10){
                if(node[y][x].dir[3] == 0){
                    node[y][x].dir[3] = 1;
                    node[y][x+1].dir[2] = 1;
                    answer++;
                }
                x++;
            }
        }
        else if(dirs[i] == 'L'){
            if(x > 0){
                if(node[y][x].dir[2] == 0){
                    node[y][x].dir[2] = 1;
                    node[y][x-1].dir[3] = 1;
                    answer++;
                }
                x--;
            }
        }
    }
    return answer;
}