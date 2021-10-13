#include <vector>
#include <iostream>
#include <string>
using namespace std;

string puzzle[9];

bool check(int x, int y, int num){
    for(int i=0;i<9;i++){
        if(puzzle[y][i] == ('0' + num)) {
            return false;
        }
        if(puzzle[i][x] == ('0' + num)) {
            return false;
        }
    }
    int dx=x/3, dy=y/3;
    for(int j=3*dy;j<3*(dy+1);j++){
        for(int i=3*dx;i<3*(dx+1);i++){
            if(puzzle[j][i] == ('0' + num)) {
                return false;
            }
        }
    }
    return true;
}

int solution(int cnt){
    if(cnt==81) return 1;
    int y = cnt/9;
    int x = cnt%9;

    if(puzzle[y][x] == '0'){
        for(int i=1;i<=9;i++){
            if(check(x, y, i)){
                puzzle[y][x] = '0' + i;
                if(solution(cnt+1) == 1) return 1;
            }
        }
        puzzle[y][x] = '0';
    }
    else{
        if(solution(cnt+1) == 1) return 1;
    }
    return -1;
}

int main(){
    for(int i=0;i<9;i++){
        cin>>puzzle[i];
    }
    solution(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<puzzle[i][j];
        }
        cout<<"\n";
    }

}