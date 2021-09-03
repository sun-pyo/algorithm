#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> start_end;

int count_one_seconds(int start){
    int count = 0;
    int end = start + 999;
    for(pair<int, int> start_end_time : start_end){
        if( start_end_time.first <= end && start_end_time.second >= start ) count++;
    }
    return count;
}

int to_seconds(string s){
    int h = stoi(s.substr(11, 2));
    int m = stoi(s.substr(14, 2));
    int ss = stod(s.substr(17, 6)) * 1000;
    return h*3600*1000 + m*60*1000 + ss;
}

int solution(vector<string> lines) {
    int answer = 0;
    int end, start, count, p;
    for(string line : lines){
        end = to_seconds(line);
        start = end - stod(line.substr(24))*1000 + 1;
        start_end.push_back({start, end});
    }
    
    for(int i=0;i<start_end.size();i++){
        answer = max(answer, count_one_seconds(start_end[i].first));
        answer = max(answer, count_one_seconds(start_end[i].second));
    }
    return answer;
}