#include <string>
#include <vector>

using namespace std;

long long DP[100][100] = {0,};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int x, y;
    for(vector<int> puddle : puddles){
        x = puddle[0] - 1;
        y = puddle[1] - 1;
        DP[y][x] = -1;
    }
    DP[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(DP[i][j] == -1) continue;
            if(i-1 >= 0 && DP[i-1][j] != -1) DP[i][j] += DP[i-1][j]%1000000007;
            if(j-1 >= 0 && DP[i][j-1] != -1) DP[i][j] += DP[i][j-1]%1000000007;
        }
    }
    answer = DP[n-1][m-1]%1000000007;
    return answer;
}