#include <string>
#include <vector>

#define INF 2000000000

using namespace std;

string solution(string s) {
    string answer = "";
    int min = INF, max = -INF; 
    int start = 0, size = 1;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            string num_str;
            num_str = s.substr(start, size);
            int num;
            num = stoi(num_str);
            if(min>num) min = num;
            if(max<num) max = num;
            start = i+1;
            size = 1;
        }
        else{
            size++;
        }
    }
    string num_str;
    num_str = s.substr(start);
    int num;
    num = stoi(num_str);
    if(min>num) min = num;
    if(max<num) max = num;
    answer = to_string(min) + " " + to_string(max);
    return answer;
}