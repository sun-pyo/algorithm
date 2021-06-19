#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, num;
    priority_queue<int> pq;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        pq.push(num);
    }
    long long result=0;
    int i=1;
    while(!pq.empty()){
        num = pq.top();
        num = num - (i-1);
        if(num > 0) result += num; 
        i++;
        pq.pop();
    }
    cout<<result;
}