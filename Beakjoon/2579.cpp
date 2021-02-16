#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int DP[301][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> score;
    int N;
    cin>>N;
    score.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>score[i];
    }

    DP[0][0] = 0;
    DP[0][1] = 0;
    for(int i=1;i<=N;i++){
        if(i >= 2){
            DP[i][1] = max(DP[i-2][1],DP[i-2][0]) + score[i];
        }else{
            DP[i][1] = score[i];
        }
        DP[i][0] = DP[i-1][1] + score[i];
    }
    
    cout<<max(DP[N][0], DP[N][1]);
}