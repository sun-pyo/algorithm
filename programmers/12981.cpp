#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> check_map;
    char last = words[0][0];
    for(int i=0;i<words.size();i++){
        if(last == words[i][0] && check_map.end() == check_map.find(words[i])){
            check_map[words[i]] = true;
            last = words[i][words[i].size()-1];
        }
        else{
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
    }
    if(answer.empty()) answer = {0, 0};

    return answer;
}