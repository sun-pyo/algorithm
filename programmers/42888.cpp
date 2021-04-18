#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid_list;
    string uid, nickname, command;
    map<string, string> uid_name;
    for(int i=0;i<record.size();i++){
        string temp = record[i];
        int curr = temp.find(' ');
        command = temp.substr(0, curr);
        int pre = curr + 1;
        curr = temp.find(' ', pre);
        uid = temp.substr(pre, curr-pre);
        if(command != "Leave")
            nickname = temp.substr(curr+1);
        if(command == "Enter"){
            uid_name[uid] = nickname;
            answer.push_back("님이 들어왔습니다.");
            uid_list.push_back(uid);
        }
        else if(command == "Leave"){
            answer.push_back("님이 나갔습니다.");
            uid_list.push_back(uid);
        }
        else if(command == "Change"){
            uid_name[uid] = nickname;
        }
    }
    for(int i=0;i<answer.size();i++){
        answer[i] = uid_name[uid_list[i]] + answer[i];
    }
    
    return answer;
}