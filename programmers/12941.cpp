#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    priority_queue<int> A_pq, B_pq;
    for(int i=0;i<A.size();i++){
        A_pq.push(-A[i]);
        B_pq.push(B[i]);
    }
    while(!A_pq.empty()){
        answer += B_pq.top() * (-A_pq.top());
        B_pq.pop();
        A_pq.pop();
    }
    
    return answer;
}