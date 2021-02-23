#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long DP[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N;
        cin>>N;

        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 1;

        for(int i=3;i<N;i++){
            DP[i] = DP[i-3] + DP[i-2];
        }

        cout<<DP[N-1]<<"\n";
        memset(DP, 0, sizeof(DP));
    }
}