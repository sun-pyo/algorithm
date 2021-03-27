#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    char temp;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' ') {
            temp = s[i];
            first = true;
        }
        else if(first){
            if(s[i] >= 'a' && s[i] <= 'z')
                temp = s[i] + 'A' - 'a';
            else temp = s[i];
            first = false;
        }
        else{
            if(s[i] >= 'A' && s[i] <= 'Z'){
                temp = s[i] + 'a' - 'A';
            }
            else temp = s[i];
        }
        answer.push_back(temp);
    }
    return answer;
}