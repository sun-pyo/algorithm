#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    int DP[41][2];

    vector<int> arr;    
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    DP[0][0] = 1;
    DP[0][1] = 0;

    DP[1][0] = 0;
    DP[1][1] = 1;
    
    for(int i=2;i<=40;i++){
        DP[i][0] = DP[i-1][0] + DP[i-2][0];
        DP[i][1] = DP[i-1][1] + DP[i-2][1];
    }

    for(int i=0;i<N;i++){
        cout<<DP[arr[i]][0]<<" "<<DP[arr[i]][1]<<"\n";
    }
}