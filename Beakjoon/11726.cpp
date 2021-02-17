#include <iostream>
#include <vector>

using namespace std;

int DP[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    DP[0] = 1;
    DP[1] = 2;
    for(int i=2;i<n;i++){
        DP[i] = (DP[i-2] + DP[i-1])%10007;
    }
    cout<<DP[n-1];
}