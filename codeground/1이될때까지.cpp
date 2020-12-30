#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int N, k, count = 0;
    scanf("%d %d", &N, &k);

    while(N!=1){
        if(N%k == 0){
            N/=k;
            count++;
        }
        else{
            N--;
            count++;
        }
    }
    printf("%d",count);
}