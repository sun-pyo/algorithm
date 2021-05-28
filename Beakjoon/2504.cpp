#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int temp = 1, answer = 0;
    stack<char> st;

    cin>>input;

    for(int i=0;i<input.size();i++){
        if(input[i] == '('){
            temp *= 2;
            st.push(input[i]);
        }
        else if(input[i] == '['){
            temp *= 3;
            st.push(input[i]);
        }
        else if(input[i] == ')'){
            if(st.empty() || st.top() == '['){
                cout<<"0\n";
                return 0;
            }
            else if(input[i-1] == '('){
                answer += temp;
            }
            st.pop();
            temp /= 2;
        }
        else if(input[i] == ']'){
            if(st.empty() || st.top() == '('){
                cout<<"0\n";
                return 0;
            }
            else if(input[i-1] == '['){
                answer += temp;
            }
            st.pop();
            temp /= 3;
        }
    }
    if(!st.empty()){
        cout<<"0\n";
    }
    else{
        cout<<answer<<"\n";
    }

}