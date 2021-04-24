#include <string>
#include <vector>

using namespace std;

long long cal(long long num1, long long num2, char target){
    if(target == '*')
        return num1 * num2;
    else if(target == '+')
        return num1 + num2;
    else if(target == '-')
        return num1 - num2;
}

long long ab(long long num) {
    if(num < 0) return -num;
    else return num;
}

long long calculate(vector<long long> num, vector<char> operator_, vector<char> target){
        for(int k=0;k<3;k++){
            for(int i=0;i<operator_.size();i++){
                if(operator_[i] == target[k]){
                    num[i] = cal(num[i],num[i+1],target[k]);
                    num.erase(num.begin() + i + 1);
                    operator_.erase(operator_.begin()+i);
                    i--;
                }
            }
        }
    return num[0];
}

long long solution(string expression) {
    long long answer = 0, temp;
    vector<long long> num;
    vector<char> operator_;
    vector<vector<char>> target = {{'*', '+', '-'}, {'+', '-', '*'}, {'-', '*', '+'},
                                  {'*', '-', '+'}, {'+', '*', '-'}, {'-', '+', '*'}};
    int cnt = 0, pos = 0;
    for(int i=0;i<expression.size();i++){
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            operator_.push_back(expression[i]);
            num.push_back(stoll(expression.substr(pos, cnt)));
            pos = i+1;
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    num.push_back(stoll(expression.substr(pos, cnt)));
    for(int i=0;i<target.size();i++)
    {
        temp = ab(calculate(num, operator_, target[i]));
        if(temp > answer) answer = temp;
    }
    return answer;
}