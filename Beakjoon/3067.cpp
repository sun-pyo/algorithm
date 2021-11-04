#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int DP[10001] = {0,};

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N, coin, target;
        vector<int> coins;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>coin;
            coins.push_back(coin);
        }        
        cin>>target;
        memset(DP, 0, sizeof(DP));
        for(int i=0;i<coins.size();i++){
            coin = coins[i];
            DP[coin]++;
            for(int k=1;k<=target;k++){
                if(k - coin >= 0)
                    DP[k] += DP[k - coin];
            }
        }
        cout<<DP[target]<<"\n";
    }
}