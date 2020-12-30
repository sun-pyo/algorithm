#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    result = 0;

    if(N/500 >= 1)
    {
        result += N/500;    
        N %= 500;
    }
    if(N/100 >= 1){
        result += N/100;
        N %= 100;
    }
    if(N/50 >= 1){
        result += N/50;
        N %= 50; 
    }
    result += (N/10);
    printf("%d",N);
}