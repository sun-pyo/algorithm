#include <vector>
#include <iostream>

using namespace std;

vector<int> DP(10001);

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N, M, k;
        cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        cin>>M;
        fill(DP.begin(), DP.end(), 0);

        for(int i=0;i<N;i++){
            k = arr[i]; 
            DP[k]++;
            for(int j=k;j<=M;j++){
                DP[j] += DP[j - k];
            }
        }
        cout<<DP[M]<<"\n";
    }
}