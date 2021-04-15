#include <string>
#include <vector>

using namespace std;

string to_binary(int num){
    string res = "";
    while(num != 0){
        if(num%2 == 0) res = "0" + res;
        else res = "1" + res;
        num/=2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    int one_cnt = 0;
    int zero_cnt = 0;
    int cnt = 0;
    while(s != "1"){
        cnt++;
        one_cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') one_cnt++;
            else zero_cnt++;
        }
        s = to_binary(one_cnt);
    }
    answer = {cnt,zero_cnt};
    return answer;
}