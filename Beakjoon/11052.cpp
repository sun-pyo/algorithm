#include <iostream>
#include <vector>

using namespace std;

int DP[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    
    vector<int> P;
    P.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>P[i];
        DP[i] = P[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=i/2;j++){
            if(DP[i] < DP[j] + DP[i-j])
                DP[i] = DP[j] + DP[i-j];
        }
    }

    int answer = 0;
    for(int i=1;i<=N;i++){
        if(answer < DP[i])
            answer = DP[i];
    }
    cout<<answer;

}