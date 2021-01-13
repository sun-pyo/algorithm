#include <stdio.h>
#include <vector>
using namespace std;

int DP[1000];
vector<int> A;

int main(){
    int N, num;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&num);
        A.push_back(num);
        DP[i] = num;
    }

    for(int i = 0;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i] > A[j]){
                DP[i] = max(DP[j]+A[i], DP[i]);
            }
        }
    }

    int answer = 0;
    for(int i = 0;i<N;i++){
        answer = max(answer, DP[i]);
    }

    printf("%d", answer);
}