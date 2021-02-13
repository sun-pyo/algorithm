#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, num;
    cin>>n>>k;

    vector<int> coin; 
    for(int i=0;i<n;i++){
        cin>>num;
        coin.push_back(num);
    }
    
    sort(coin.begin(), coin.end());

    DP[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j-coin[i] >= 0){
                DP[j] = DP[j-coin[i]] + DP[j];
            }
        }
    }

    cout<<DP[k];


}