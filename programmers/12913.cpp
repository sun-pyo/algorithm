#include <iostream>
#include <vector>

using namespace std;

int DP[100000][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=0;i<4;i++) DP[0][i] = land[0][i];
    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            int max = -1;
            for(int k=0;k<4;k++){
                if(j==k) continue;
                if(max < DP[i-1][k]) max = DP[i-1][k]; 
            }
            DP[i][j] = max + land[i][j];
        }
    }
    for(int i=0;i<4;i++){
        if(answer < DP[land.size()-1][i])
            answer = DP[land.size()-1][i];
    }
    return answer;
}