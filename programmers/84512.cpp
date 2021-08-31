#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dict;
string alphabet[] = {"A", "E", "I", "O", "U"};

void create_dict(string s){
    if(s.size() > 5) return;
    dict.push_back(s);
    for(int i=0;i<5;i++){
        create_dict(s+alphabet[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for(int i=0;i<5;i++){
        create_dict(alphabet[i]);
    }
    sort(dict.begin(), dict.end());
    for(int i=0;i<dict.size();i++){
        if(word == dict[i]) answer = i+1;
    }
    return answer;
}