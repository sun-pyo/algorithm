#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<pair<int, int>> arr;
    for(int i=0;i<array.size();i++){
        arr.push_back(make_pair(array[i], i+1));
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<commands.size();i++){
        int count = 0;
        for(int k=0;k<arr.size();k++){
            if(arr[k].second >= commands[i][0] && arr[k].second <= commands[i][1]){
                count++;
                if(count == commands[i][2]) {
                    answer.push_back(arr[k].first);
                    break;
                }
            }
        }
    }
    
    return answer;
}