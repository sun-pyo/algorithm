#include <string>
#include <vector>

using namespace std;

char step123(char curr, char last){
    if(curr >= 'A' && curr <= 'Z'){
        return ('a' + curr - 'A');
    }
    else if(curr == '.' && last == '.'){
        return '\0';
    }
    else if((curr >= 'a' && curr <= 'z') || (curr >= '0' && curr <= '9') || curr == '-' || curr == '_' || curr == '.'){
       return curr; 
    }
    return '\0';
}

string step4(string answer){
    if(!answer.empty()){
        if(answer[0] == '.') answer = answer.substr(1);
        if(answer.back() == '.') answer = answer.substr(0, answer.size()-1);
    }
    return answer;
}

string solution(string new_id) {
    string answer = "";
    char last = '\0', curr;
    for(int i=0;i<new_id.size();i++){
        curr = step123(new_id[i], last);
        if(curr != '\0') {
            answer += curr; 
            last = new_id[i];
        }
    }
    answer = step4(answer);
    if(answer.empty()){
        answer += "a";
    }
    if(answer.size() > 15) answer = answer.substr(0, 15);
    if(answer.back() == '.') answer = answer.substr(0, answer.size()-1);
    if(answer.size() <= 2){
        while(answer.size() < 3){
            answer += answer.back();
        }
    }
    return answer;
}