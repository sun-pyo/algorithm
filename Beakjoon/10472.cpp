#include <iostream>
#include <vector>
#include <string>

using namespace std;


int answer;

vector<vector<int>> cross = {
    {0,1,3}, {0,1,2,4}, {1,2,5},
    {0,3,4,6}, {1,3,4,5,7}, {2,4,5,8},
    {3,6,7}, {4,6,7,8}, {5,7,8}
};

void dfs(int idx, int cnt,string curr, string target){
    if(curr == target){
        if(answer > cnt){
            answer = cnt;
        }
        return;
    }
    else if(idx >= 9) return;
    dfs(idx + 1, cnt, curr, target);
    for(int i=0;i<cross[idx].size();i++){
        int change_idx = cross[idx][i];
        if(curr[change_idx] == '0') curr[change_idx] = '1';
        else curr[change_idx] = '0';
    }
    dfs(idx + 1, cnt+1, curr, target);
}

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        vector<string> ori_map;
        string map;
        ori_map.resize(3);
        for(int i=0;i<3;i++){
            cin>>ori_map[i];
            for(int j=0;j<3;j++){
                if(ori_map[i][j] == '*') map.push_back('1');
                else map.push_back('0'); 
            }
        }
        answer = 1024;
        dfs(0, 0, "000000000", map);
        cout<<answer<<"\n";
    }
}