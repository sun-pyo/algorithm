#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<string, int> Map;
vector<int> arr[4][3][3][3];

void push(vector<int> idx, int cnt, int score){
    if(cnt == idx.size()-1) {
        arr[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        arr[idx[0]][idx[1]][idx[2]][0].push_back(score);
        return;
    }
    push(idx, cnt+1, score);
    idx[cnt] = 0;
    push(idx, cnt+1, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    Map["-"] = 0;
    Map["java"] = 1;
    Map["python"] = 2;
    Map["cpp"] = 3;
    
    Map["backend"] = 1;
    Map["frontend"] = 2;
    
    Map["junior"] = 1;
    Map["senior"] = 2;
    
    Map["chicken"] = 1;
    Map["pizza"] = 2;

    vector<int> answer;
    
    int pre, pos, res;
    int l, b, c, f;
    int score;
    string str_arr[5];
    for(int i=0;i<info.size();i++){
        string temp = info[i];
        pre = -1;
        for(int i=0;i<5;i++){
            pos = temp.find(" ", pre+1);
            str_arr[i] = temp.substr(pre+1, pos-pre-1);
            pre = pos;
        }
        l = Map[str_arr[0]];
        b = Map[str_arr[1]];
        c = Map[str_arr[2]];
        f = Map[str_arr[3]];
        score = stoi(str_arr[4]);
        push({l, b, c, f}, 0, score);
        
    }
    for(int a=0;a<4;a++){
        for(int b=0;b<3;b++){
            for(int c=0;c<3;c++){
                for(int d=0;d<3;d++) sort(arr[a][b][c][d].begin(), arr[a][b][c][d].end());
            }
        }
    }
    for(int i=0;i<query.size();i++){
        string q = query[i];
        pre = -1;
        for(int i=0;i<3;i++){
            pos = q.find(" and ", pre+1);
            str_arr[i] = q.substr(pre+1, pos-pre-1);
            pre = pos + 4;
        }
        for(int i=3;i<5;i++){
            pos = q.find(" ", pre+1);
            str_arr[i] = q.substr(pre+1, pos-pre-1);
            pre = pos;
        }
        l = Map[str_arr[0]];
        b = Map[str_arr[1]];
        c = Map[str_arr[2]];
        f = Map[str_arr[3]];
        if(str_arr[4] == "-") score = 1;
        else score = stoi(str_arr[4]);
        vector<int>::iterator low = lower_bound(arr[l][b][c][f].begin(), arr[l][b][c][f].end(), score);
        res = arr[l][b][c][f].end() - low;
        answer.push_back(res);
    }
    return answer;
}