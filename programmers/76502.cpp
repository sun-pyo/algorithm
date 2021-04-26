#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        vector<char> stack;
        stack.push_back(s[0]);
        for(int k=1;k<s.size();k++){
            if( (stack.back() == '(' && s[k] == ')') || (stack.back() == '[' && s[k] == ']') || (stack.back() == '{' && s[k] == '}') ) stack.pop_back();
            else stack.push_back(s[k]);
        }
        if(stack.empty()) answer++;
        string first = s.substr(0,1);
        s = s.substr(1,s.size()-1) + first; 
    }
    return answer;
}