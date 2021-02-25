#include <iostream>
#include <vector>

using namespace std;

int DP[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;

    for(int n=1;n<=N;n++){
        for(int k=0;k<=K;k++){
            if(k==0 || k==n){
                DP[n][k] = 1;
            }
            else{
                DP[n][k] = (DP[n-1][k-1] + DP[n-1][k])%10007;
            }
        }
    }
    cout<<DP[N][K];
}