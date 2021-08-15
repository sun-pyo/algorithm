#include <vector>


using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int DP[500][500][2] = {0,};
    DP[0][0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(city_map[i][j] == 1) continue;
            if(j-1 >= 0){
                DP[i][j][0] += DP[i][j-1][0];
                if(city_map[i][j-1] == 0) DP[i][j][0] += DP[i][j-1][1];
                DP[i][j][0] %= MOD;
            }
            if(i-1 >= 0){
                DP[i][j][1] = DP[i-1][j][1];
                if(city_map[i-1][j] == 0 ) DP[i][j][1] += DP[i-1][j][0];
                DP[i][j][1] %= MOD;
            }
        }
    }
    answer = (DP[m-1][n-1][0] + DP[m-1][n-1][1])%MOD;
    return answer;
}