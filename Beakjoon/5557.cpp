#include <iostream>
#include <vector>

using namespace std;
vector<long long> arr;
long long visit[100][21] = {0,};
int N;
long long target;

long long sol(int idx, long long num){
    if(idx == N-1){
        if(num == target) return 1;
        else return 0;
    }

    if(visit[idx][num] != 0) return visit[idx][num];

    if(num + arr[idx] <= 20 ) visit[idx][num] += sol(idx + 1, num + arr[idx]);
    if(num - arr[idx] >= 0) visit[idx][num] += sol(idx + 1, num - arr[idx]);

    return visit[idx][num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }
    target = arr.back();
    cout<<sol(1, arr[0]);
}