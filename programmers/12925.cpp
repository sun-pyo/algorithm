#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string sub;
    if(s[0] == '-'){
        sub = s.substr(1);
        return stoi(sub) * -1;
    }
    else if(s[0] == '+'){
        sub = s.substr(1);
        return stoi(sub);
    }
    else return stoi(s);
}