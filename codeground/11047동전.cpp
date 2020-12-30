#include <stdio.h>

using namespace std;

int A[10];

int main(){
    int N,K;
    scanf("%d %d", &N, &K);

    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }

    int result = 0;

    for(int i=N-1;i>=0;i--){
        if(K >= A[i]){
            result += K/A[i];
            K = K%A[i];
        }
    }

    printf("%d",result);

}