#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> category_cnt;
    for(int i=0;i<clothes.size();i++){
        string category = clothes[i][1];
        if(category_cnt.find(category) == category_cnt.end()){
            category_cnt[category] = 1;
        }
        else{
            category_cnt[category]++;
        }
    }
    for(auto cnt : category_cnt){
        answer *= (cnt.second+1);
    }
    answer--;
    return answer;
}