#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int DP[100001] = {0,};
int coins[] = {1, 2, 5, 7};

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++) DP[i] = N;
    for(int i=0;i<4;i++){
        DP[coins[i]]  = 1;
    }
    for(int i=3;i<=N;i++){
        for(int k=0;k<4;k++){
            if(i - coins[k] >= 1)
                DP[i] = min(DP[i], DP[i - coins[k]] + 1); 
        }
    }
    cout<<DP[N];
}