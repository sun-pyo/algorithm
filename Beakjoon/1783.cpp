#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    long long N, M;
    scanf("%lld %lld", &N, &M);
    long long answer;
    if(N > 2 && M > 6){
        answer = M - 6 + 4;
    }
    else {
        if(N == 1 || M == 1){
            answer = 1;
        }
        else if(N==2){
            answer = (M-1)/2 + 1;
        }
        else {
            answer = M;
        }

        if(answer > 4){ 
            answer = 4;
        }
    }
    printf("%lld",answer);
}