#include <string>
#include <iostream>
#include <vector>

using namespace std;

string get_reverse(vector<char> &str){
    string res = "";
    while(!str.empty()){
        res += str.back();
        str.pop_back();
    }
    return res;
}

int main(){
    string input, answer = "";
    vector<char> tag;
    vector<char> str;
    getline(cin, input);
    input += " ";
    for(int i=0;i<input.size();i++){
        if(input[i] == '<'){
            tag.push_back('<');
            answer += get_reverse(str);
            answer += "<";
        }
        else if(input[i] == '>'){
            tag.pop_back();
            answer += ">";
        }
        else if(tag.empty()){
            if(input[i] == ' '){
                answer += get_reverse(str);
                answer += " ";
            }
            else{
                str.push_back(input[i]);
            }
        }
        else answer += input[i];
    }
    cout<<answer<<"\n";
}