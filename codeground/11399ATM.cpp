#include <stdio.h>
#include <algorithm>

using namespace std;

int P[1000];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d", &P[i]);
    }
    
    sort(P, P+N);
    
    int result = 0, sum = 0;
    for(int i=0;i<N;i++){
        sum += P[i];    
        result += sum;
    }
    printf("%d",result);
}