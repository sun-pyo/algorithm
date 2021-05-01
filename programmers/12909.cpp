#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> st;
    for(int i=0;i<s.size();i++){
        if(st.empty() || st.back() == ')' || s[i] == '('){
            st.push_back(s[i]);
        }
        else{
            st.pop_back();
        }
    }
    if(!st.empty()) answer = false;

    return answer;
}