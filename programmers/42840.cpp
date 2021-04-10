#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> out;
    out.resize(3);
    out[0] = {1, 2, 3, 4, 5};
    out[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    out[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt[] = {0, 0, 0};
    int max_cnt = 0;
    for(int i=0;i<answers.size();i++){
        for(int k=0;k<3;k++){
            int idx = i%out[k].size();
            if(out[k][idx] == answers[i]){
                cnt[k]++;
                if(cnt[k] > max_cnt) max_cnt = cnt[k];
            }
        }
    }
    for(int i=0;i<3;i++){
        if(cnt[i] == max_cnt) answer.push_back(i+1);
    }
    return answer;
}