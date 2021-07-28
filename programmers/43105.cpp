#include <string>
#include <vector>

using namespace std;

int DP[500][500] = {0,};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    DP[0][0] = triangle[0][0];
    for(int j=1;j<triangle.size();j++){
        for(int i=0;i<triangle[j].size();i++){
            if(i>0) DP[j][i] = max(DP[j-1][i-1], DP[j-1][i]) + triangle[j][i];
            else DP[j][i] = DP[j-1][i] + triangle[j][i];
        }
    }
    int last_line = triangle.back().size() - 1;
    for(int i=0;i<=last_line;i++){
        answer = max(answer, DP[last_line][i]);
    }
    return answer;
}