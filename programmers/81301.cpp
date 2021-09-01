#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, int> dict;
    dict["zero"] = 0;
    dict["one"] = 1;
    dict["two"] = 2;
    dict["three"] = 3;
    dict["four"] = 4;
    dict["five"] = 5;
    dict["six"] = 6;
    dict["seven"] = 7;
    dict["eight"] = 8;
    dict["nine"] = 9;
    string temp_s = "";
    for(char ch : s){
        temp_s += ch;
        if(ch >= '0' && ch <= '9'){
            answer *= 10;
            answer += stoi(temp_s);
            temp_s = "";
        }
        else if(dict.find(temp_s) != dict.end()){
            answer *= 10;
            answer += dict[temp_s];
            temp_s = "";
        }
    }
    return answer;
}