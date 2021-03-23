#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int m=0;m<arr1.size();m++){
        vector<int> temp;
        for(int k=0;k<arr2[0].size();k++){
            int sum = 0;
            for(int n=0;n<arr2.size();n++){
                sum += arr1[m][n] * arr2[n][k];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}