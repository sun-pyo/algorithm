#include <string>
#include <set>
#include <vector>

using namespace std;

bool check(vector<int> ans, int num){
    for(int i=0;i<ans.size();i++){
        if( (ans[i] & num) == ans[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> answer_list;
    int col = relation[0].size(), row = relation.size();
    for(int i=1;i< (1<<col);i++){
        set<string> s;
        for(int j=0;j<row;j++){
            string temp = "";
            for(int k=0;k<col;k++){
                if((i & (1<<k)) != 0){
                    temp += "_" + relation[j][k];
                }
            }
            s.insert(temp);
        }
        if(s.size() == row && check(answer_list, i)){
            answer_list.push_back(i);
        }
    }
    answer = answer_list.size();
    return answer;
}