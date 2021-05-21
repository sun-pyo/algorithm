#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string str, answer = "";
    cin>>str;
    vector<char> op;
    for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            op.push_back(str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!op.empty() && op.back() != '('){
                answer += op.back();;
                op.pop_back();
            }
            op.push_back(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(!op.empty() && (op.back() == '*' || op.back() == '/')){
                answer += op.back();;
                op.pop_back();
            }
            op.push_back(str[i]);
        }
        else if(str[i] == ')'){
            while(!op.empty() && op.back() != '('){
                answer += op.back();;
                op.pop_back();
            }
            op.pop_back();
        }
        else{
            answer += str[i];
        }
    }
    while(!op.empty()){
        answer += op.back();;
        op.pop_back();
    }
    cout<<answer;
}