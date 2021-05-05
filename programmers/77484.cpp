#include <string>
#include <vector>

using namespace std;

int get_rank(int score){
    if(score == 0) return 6;
    else return 7 - score;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int score = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j=0;j<lottos.size();j++){
            if(lottos[i] == win_nums[j]){
                score++;
                break;
            }
        }
    }
    answer.push_back(get_rank(score+zero_cnt));
    answer.push_back(get_rank(score));
    return answer;
}