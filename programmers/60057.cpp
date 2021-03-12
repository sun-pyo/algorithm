#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_count(int count){
    int res = 0;
    while(count){
        count/=10;
        res++;
    }
    return res;
}

int get_length(string s,int n){
    vector<string> split_str;
    for(int i=0;i<s.size()/n;i++){
        string str = s.substr(i*n, n);
        split_str.push_back(str);
    }
    int count = 1;
    int res = 0;
    
    for(int i=0;i<split_str.size();i++){
        if(i == split_str.size() -1 ){
            res += n;
            if(count > 1) res += get_count(count);
        }
        else if(split_str[i].compare(split_str[i+1]) == 0){
            count++;
        }
        else{
            res += n;
            if(count > 1) res += get_count(count);
            count = 1;
        }
    }
    if(s.size()%n != 0){
        res += s.size()%n;
    }
    return res;
}

int solution(string s) {
    int answer = 1000;
    for(int i=1;i<=s.size();i++){
        int res = get_length(s, i);
        if(res < answer) {
            answer =res;
        }
    }
    return answer;
}

int main(){
    string s = "a";
    //cout<<get_length(s, 3);
    cout<<solution(s);

}