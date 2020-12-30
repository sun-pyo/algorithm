#include <iostream>
#include <cstdio>

using namespace std;

int DP[1001];
int A[1001];

int main(){
    int N, max_ = 0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }
    fill(DP,&DP[1001],1);
     for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            if(A[i] > A[j]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
    }

    for(int i=1;i<=N;i++)
        max_ = max(max_, DP[i]);
    printf("%d", max_);
}