#include <string>
#include <vector>
#include <iostream>
using namespace std;

string step(string s){
    if(s == "") return s;
    int c = 0;
    string u, v;
    bool flag = true;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            c++;
        }
        else{
            c--;
        }
        if(c == -1) flag = false;
        if(c == 0){
            u = s.substr(0, i+1);
            if(i==s.size()-1)
                v = "";
            else 
                v = s.substr(i+1);
            break;
        }
    }
    string res = "";
    if(flag){
        res += u;
        res += step(v);
    }
    else{
        res += "(";
        res += step(v);
        res += ")";
        for(int i=1;i<u.size()-1;i++){
            if(u[i] == ')') res += "(";
            else res += ")";
        }
    }
    return res;
    
}

string solution(string p) {
    string answer = "";
    answer = step(p);
    
    return answer;
}