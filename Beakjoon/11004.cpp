#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<long long> heap; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;
    long long num;
    for(int i=0;i<N;i++){
        cin>>num;
        heap.push(-num);
    }
    for(int i=0;i<K-1;i++) heap.pop();
    cout<<-heap.top();
}