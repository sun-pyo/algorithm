#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> str_left;
vector<char> str_right;
void solution(char cmd){
    if(cmd == 'P'){
        char ch;
        cin>>ch;
        str_left.push_back(ch);
    }
    else if(cmd == 'L'){
        if(!str_left.empty()){
            str_right.push_back(str_left.back());
            str_left.pop_back();
        } 
    }
    else if(cmd == 'D'){
        if(!str_right.empty()){
            str_left.push_back(str_right.back());
            str_right.pop_back();
        }
    }
    else if(cmd == 'B'){
        if(!str_left.empty()){
            str_left.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp_str;
    cin>>temp_str;

    for(int i=0;i<temp_str.size();i++){
        str_left.push_back(temp_str[i]);
    }

    int M;
    cin>>M;
    for(int m=0;m<M;m++){
        char cmd;
        cin>>cmd;
        solution(cmd);
    }

    for(int i=0;i<str_left.size();i++)
        cout<<str_left[i];
    for(int i=str_right.size()-1;i>=0;i--)
        cout<<str_right[i];

}