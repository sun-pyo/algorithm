#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int idx[] = {0, -1, 1};
    vector<int> state(n+1, 1);
    for(int i=0;i<lost.size();i++){
        state[lost[i]]--;
        answer--;
    }
    sort(reserve.begin(), reserve.end());
    for(int i=0;i<reserve.size();i++){
        if(state[reserve[i]] == 0){
            state[reserve[i]]++;
            answer++;
            reserve.erase(reserve.begin()+i);
            i--;
        }
    }
    for(int i=0;i<reserve.size();i++){
        for(int k=0;k<3;k++){
            if(reserve[i] + idx[k] >= 1 && reserve[i] + idx[k] <= n && state[reserve[i] + idx[k]] == 0) {
                state[reserve[i] + idx[k]]++;
                answer++;
                break;
            }
        }
    }
    return answer;
}