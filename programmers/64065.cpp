#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a.size()<b.size();
}

int num[100001];

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> set;
    vector<int> temp;
    bool in = false;
    int start_idx, size;
    for(int i=1;i<s.size()-1;i++){
        if(s[i] == '{'){
            in = true;
            temp.clear();
            size = 0;
            start_idx = i+1;
        }
        else if(s[i] == '}'){
            in = false;
            temp.push_back(stoi(s.substr(start_idx, size)));
            num[stoi(s.substr(start_idx, size))]++;
            if(set.size() < temp.size()){
                set = temp;
            }
                
        }
        else if(in && s[i] == ','){
            temp.push_back(stoi(s.substr(start_idx, size)));
            num[stoi(s.substr(start_idx, size))]++;
            start_idx = i+1;
            size = 0;
        }
        else if(s[i] != ',') size++;
    }
    answer.resize(set.size());
    for(int i=0;i<set.size();i++){
        answer[set.size()- num[set[i]]] = set[i]; 
    }
    return answer;
}