#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int DP[100];

int main(){
    int n,s;
    scanf("%d %d", &n, &s);
    memset(DP,0,sizeof(DP));
    
    DP[1] = s-1;
    
    for(int i=2;i<=n;i++){
        if(i%2 != 0){
            DP[i] = (DP[i-1] + (2*(i-1)-2) + (2*i-1))%9;
        }
        else{
            DP[i] = (DP[i-1] + 1)%9;
        }
    }
    int answer = DP[n]+1;
    if(answer == 9)
        answer = 1;
    else if(answer == 0)
        answer = 9;
    printf("%d",answer);
}