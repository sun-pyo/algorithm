#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int DP[500][500];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<vector<int>> map;
    cin>>n;
    map.resize(n);
    for(int i=0;i<n;i++){
        map[i].resize(i+1);
        for(int j=0;j<=i;j++){
            cin>>map[i][j];
        }
    }

    DP[0][0] = map[0][0];

    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j-1 >= 0){
                DP[i][j] = DP[i-1][j-1];
            }
            if(map[i-1].size() > j){
                DP[i][j] = max(DP[i][j], DP[i-1][j]);
            }
            DP[i][j] += map[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        if(answer < DP[n-1][i]) answer = DP[n-1][i];
    }
    cout<<answer;
    
}