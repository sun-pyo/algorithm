#include <iostream>
#include <vector>

using namespace std;

int DP[2000][2000] = {0,};
int V[2000] = {0,};

int sol(int k, int left, int right){
    if(left > right) return 0;
    if(DP[left][right] != 0) return DP[left][right];
    DP[left][right] = max(sol(k+1, left+1, right) + k*V[left], sol(k+1, left, right-1)+ k*V[right]);
    return DP[left][right];
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>V[i];
    }
    cout<<sol(1, 0, N-1);
}
