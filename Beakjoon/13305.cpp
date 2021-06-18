#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    long long num;
    vector<long long> road;
    vector<long long> cost;
    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>num;
        road.push_back(num);
    }
    for(int i=0;i<N;i++){
        cin>>num;
        cost.push_back(num);
    }
    long long min = cost[0], answer = 0;
    for(int i=0;i<N-1;i++){
        if(cost[i] < min) min = cost[i];
        answer += min * road[i];
    }
    cout<<answer;
}