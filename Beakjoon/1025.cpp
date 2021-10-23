#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int table[9][9] = {0,};
int N, M;

long long get_num(int x, int y, int dx, int dy){
    long long res = -1, num = table[y][x];
    int n;
    n = (int)sqrt(num);
    if(n*n == num) res = max(res, num); 
    if(dx == 0 && dy == 0) return res;
    while(true){
        x += dx;
        y += dy;
        if(!(x>=0 && x<M && y>=0 && y<N)) break;
        num *= 10;
        num += table[y][x];
        n = (int)sqrt(num);
        if(n*n == num) res = max(res, num); 
    }
    return res;
}

long long solution(int start_x, int start_y){
    long long res = -1;
    int n;
    for(int i=-start_y;i<N-start_y;i++){
        for(int j=-start_x;j<M-start_x;j++){
            res = max(res, get_num(start_x, start_y, j, i));
        }
    }
    return res;
}

int main(){
    long long answer = -1, res;
    string s;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            table[i][j] = s[j] - '0';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            res = solution(j, i);
            if(answer < res) answer = res;
        }
    }
    cout<<answer;
}