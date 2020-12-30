#include <iostream>
#include <cstdio>

using namespace std;

int DP[1001][10];


void init_DP(){
    for(int i=0;i<10;i++)
        DP[1][i] = 1;
}

void solution(int N){
    if(N==1) return;
    for(int i=0;i<10;i++){
        for (int j=i;j<10;j++){
            DP[N][i] += DP[N-1][j];
            DP[N][i] %= 10007;
        } 
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    init_DP();
    for(int i=1;i<=N;i++){
        solution(i);
    }

    int total = 0;
    for(int i=0;i<10;i++)
        total += DP[N][i];
    printf("%d", total%10007);
}