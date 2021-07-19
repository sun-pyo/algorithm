#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    int idx = 1;
    string temp, w, c;
    for(char ch='A';ch<='Z';ch++){
        temp = ch;
        dict[temp] = idx++;
    }
    
    for(int i=0;i<msg.size();i++){
        w = "";
        while(i<msg.size()){
            if(dict.find(w + msg[i]) == dict.end()) break;
            w += msg[i++];
        }
        answer.push_back(dict[w]);
        i--;
        if(i+1 < msg.size()){
            c = msg[i+1];
            dict[w+c] = idx++;
        }
    }
    
    return answer;
}