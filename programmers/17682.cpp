#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    vector<int> score;
    for(int i=0;i<dartResult.size();i++){
        if('0' <= dartResult[i] && dartResult[i] <= '9'){
            if(dartResult[i] == '1' && dartResult[i+1] == '0'){
                num = 10;
                i++;
            }
            else num = dartResult[i] - '0';
            i++;
            if(dartResult[i] == 'D') num *= num;
            else if(dartResult[i] == 'T') num *= num*num;
            score.push_back(num);
        }
        else if(dartResult[i] == '#'){
            score[score.size()-1] *= -1;
        }
        else if(dartResult[i] == '*'){
            score[score.size()-1] *= 2;
            if(score.size()-2 >= 0) score[score.size()-2] *= 2;
        }
    }
    for(int i=0;i<score.size();i++){
        answer += score[i];
    }
    return answer;
}