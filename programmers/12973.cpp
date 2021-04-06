#include <iostream>
#include<string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> stack;
    for(int i=0;i<s.size();i++){
        if(!stack.empty() && stack.back() == s[i]){
            stack.erase(stack.begin() + stack.size()-1);
        }
        else{
            stack.push_back(s[i]);
        }
    }
    if(stack.empty()) return 1;
    else return 0;
    
}