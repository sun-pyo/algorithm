#include <queue>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    priority_queue<int> pq;
    cin>>N;

    for(int i=0;i<N*N;i++){
        cin>>num;
        num = -num;
        if(pq.size() < N) pq.push(num);
        else{
            if(pq.top() > num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    cout<<-pq.top();
}