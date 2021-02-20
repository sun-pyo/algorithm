#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long DP[100][100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    vector<vector<int>> score;

    score.resize(N);
    for(int i=0;i<N;i++){
        score[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>score[i][j];
        }
    }

    DP[0][0] = 1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(DP[i][j] != 0){
                if(i+score[i][j] < N && score[i][j] != 0)
                    DP[i+score[i][j]][j] += DP[i][j];
                if(j+score[i][j] < N && score[i][j] != 0)
                    DP[i][j+score[i][j]] += DP[i][j];
            }
        }
    }
    
    cout<<DP[N-1][N-1];

}