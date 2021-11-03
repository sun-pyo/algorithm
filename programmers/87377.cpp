#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> points;
    long long A, B, C, D, E, F;
    long long x, y, min_x = LLONG_MAX, max_x = -LLONG_MAX, min_y = LLONG_MAX, max_y = -LLONG_MAX;
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;j<line.size();j++){
            A = line[i][0];
            B = line[i][1];
            E = line[i][2];
            C = line[j][0];
            D = line[j][1];
            F = line[j][2];
            if(A*D - B*C == 0) continue;
            if((E*C - A*F)%(A*D - B*C) != 0) continue;
            if((B*F - E*D)%(A*D - B*C) != 0) continue;
            y = (E*C - A*F)/(A*D - B*C);
            x = (B*F - E*D)/(A*D - B*C);
            max_x = max(max_x, x);
            min_x = min(min_x, x);
            max_y = max(max_y, y);
            min_y = min(min_y, y);
            points.push_back({x, y});
        }
    }

    int idx = 0;
    string temp = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, temp);
    for(int i=0;i<points.size();i++){
        x = points[i].first - min_x;
        y = max_y - points[i].second;
        answer[y][x] = '*';
    }
    return answer;
}