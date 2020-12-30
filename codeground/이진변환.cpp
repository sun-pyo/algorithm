#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_byte(int num){
   
    vector<int> s;
    int n;
    while(num){
        n = num % 2;
        s.push_back(n);
        num /= 2;
    }
    string str;
    int size = s.size();
    for(int i=0;i<size;i++){
        if(s.back() == 1){
            str += '1';
            s.pop_back();
        }
        else{
            str += '0';
            s.pop_back();
        }
    }
    
    return str;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0;
    int count = 0;
    string str = s;
    string new_str;
    do{
        new_str.clear();
        for(int i = 0;i<str.size();i++){
            if(str[i] == '0') {
                zero_count++;
                continue;
            }
            new_str += str[i];
        }
        str = to_byte(new_str.size());
        count++;
    }while(str != "1");
    answer.push_back(zero_count);
    answer.push_back(count);
    return answer;
}

int main(){
    string s = "01110";
    vector<int> a = solution(s);
    cout<<a[0]<<" "<<a[1];
}