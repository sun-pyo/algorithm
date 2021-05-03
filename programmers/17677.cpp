#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void string_to_set(string str1, map<string, int> &m){
    for(int i=0;i<str1.size()-1;i++){
        string temp = "  ";
        bool check = true;
        for(int k=0;k<2;k++){
            if('a' <= str1[i+k] && 'z' >= str1[i+k]){
                temp[k] = str1[i+k];
            }
            else if('A' <= str1[i+k] && 'Z' >= str1[i+k]){
                temp[k] = str1[i+k] - 'A' + 'a';
            }
            else {
                check = false;
                break;
            }
        }
        if(check){
            if(m.find(temp) == m.end())
                m[temp] = 1;
            else m[temp]++;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> str1_map, str2_map;
    string_to_set(str1, str1_map);
    string_to_set(str2, str2_map);
    if(str1_map.size() == 0 && str2_map.size() == 0) return 65536;
    int sum_inter = 0;
    int sum_union = 0;
    for(auto m : str1_map){
        string s = m.first;
        int num = m.second;
        if(str2_map.find(s) == str2_map.end()){
            sum_union += num;
        }
        else{
            int num2 = str2_map[s];
            sum_union += max(num2, num);
            sum_inter += min(num2, num);
        }
    }
    for(auto m : str2_map){
        string s = m.first;
        int num = m.second;
        if(str1_map.find(s) == str1_map.end()){
            sum_union += num;
        }
    }
    double rate = (double)sum_inter/sum_union;
    answer = rate*65536;
    
    return answer;
}