#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> check;
    vector<int> index;
    for(int i = 0;i<skill.size();i++){   
        check.push_back(skill[i]- 'A');
    }
    
    for(int i = 0;i<skill_trees.size();i++){
        int idx = 0;
        bool fail = false;
        
        for(int j = 0;j<skill_trees[i].size();j++){
            for(int c = 0;c<check.size();c++){
                if(skill_trees[i][j] - 'A' == check[c]){
                    if(c != idx){
                        fail = true;
                        break;
                    }
                    idx++;
                    break;
                }    
            }
            if(fail) break;
        }
        if(fail) continue;
        answer++;
    }
    return answer;
}