#include <string>
#include <vector>
#include <iostream>
using namespace std;

int time_to_min(string s){
    int hour = stoi(s.substr(0,2)) * 60;
    int min = stoi(s.substr(3,2));
    return hour + min;
}

bool find_m(string code, string m, int pos){
    int f = code.find(m, pos);
    if(f == string::npos) return false;
    else {
        if(f+m.size() < code.size() && code[f+m.size()] == '#') return find_m(code, m, f+1);
        return true;
    }
}

pair<string, int> check_solution(string s, string m){
    
     int pre, curr = 0;
     string start, end, name, code;
     curr = s.find(",");
     pre = curr + 1;
     start = s.substr(0,curr);
     
    curr = s.find(",", pre);
    end = s.substr(pre, curr-pre);
    pre = curr + 1;
    
    curr = s.find(",", pre);
    name = s.substr(pre, curr-pre);
    pre = curr + 1;
    
    code = s.substr(pre);
    
    
    int time = time_to_min(end) - time_to_min(start);
    
    
    string fullcode = "";
    int cnt = 0, i=0;
    while(cnt<time){
        string temp = " ";
        temp[0] = code[i%code.size()];
        i++;
        if(code[i%code.size()] == '#') {
            temp.push_back(code[i%code.size()]);
            i++;
        }
        fullcode += temp;
        cnt++;
    }
    bool check_ = find_m(fullcode, m, 0);
    if(check_) return make_pair(name, time);
    else return make_pair("", 0);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_time = -1;
    pair<string, int> temp;
    for(int i=0;i<musicinfos.size();i++){
        temp = check_solution(musicinfos[i], m);
        if(temp.first != "" && temp.second > max_time) {
            max_time = temp.second;
            answer = temp.first;
        }
    }
    if(answer != "") return answer;
    return "(None)";
}