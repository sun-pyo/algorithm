#include <iostream>
#include <cstdio>

using namespace std;

long long DP[91] = {0};

int main(){
    int N;
    scanf("%d",&N);
    DP[1] = 1;
    DP[2] = 1;
    for(int i = 3;i<=N;i++){
        DP[i] = DP[i-2] + DP[i-1];
    }
    printf("%lld",DP[N]);
}