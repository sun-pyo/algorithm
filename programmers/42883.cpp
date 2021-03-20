#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer.push_back(number[0]);
    for(int i=1;i<number.size();i++){
        for(int j=answer.size()-1;j>=0;j--){
            if(k == 0 || number[i] <= answer[j]) break;
            answer.erase(answer.begin()+j);
            k--;
        }
        if(k == 0) {
            answer += number.substr(i);
            break;
        }
        answer.push_back(number[i]);
    }
    
    return answer;
}