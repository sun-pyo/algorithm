#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    int N, num;
    scanf("%d",&N);
    priority_queue<int> heap;
    for(int i=0;i<N;i++){
        scanf("%d", &num);
        heap.push(-num);
    }

    int num1, num2, sum, answer = 0;

    while(heap.size() >= 2){
        sum = 0;
        num1 = -heap.top();
        heap.pop();
        num2 = -heap.top();
        heap.pop();
        sum = num1 + num2;
        answer += sum;
        heap.push(-sum);
    }

    printf("%d",answer);
}