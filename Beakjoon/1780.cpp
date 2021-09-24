#include <iostream>
#include <vector>

using namespace std;

int paper[2187][2187];
int answer[3] = {0, };

bool check(int x_min, int y_min, int x_max, int y_max){
    int num = paper[y_min][x_min];
    for(int y=y_min;y<=y_max;y++){
        for(int x=x_min;x<=x_max;x++){
            if(num != paper[y][x]) return false;
        }
    }
    return true;
}

void solution(int x_min, int y_min, int x_max, int y_max){
    if(check(x_min, y_min, x_max, y_max)){
        answer[paper[y_min][x_min] + 1]++;
    }
    else{
        int l = (x_max - x_min + 1)/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                solution(x_min+j*l, y_min+i*l, x_min + (j+1)*l - 1, y_min + (i+1)*l - 1);
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>paper[i][j];
        }
    }
    solution(0, 0, N-1, N-1);
    for(int i=0;i<3;i++){
        cout<<answer[i]<<"\n";
    }
}