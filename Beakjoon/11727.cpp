#include <iostream>
#include <vector>

using namespace std;

int DP[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int N;
    cin>>N;

    DP[0] = 1;
    DP[1] = 3;
    for(int i=2;i<N;i++){
        DP[i] = (DP[i-1] + 2*DP[i-2])%10007;
    }
    cout<<DP[N-1];

}