#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> menu_list;
map<string, int> count_menu;

void sol(string str, int idx, string target){
    if(idx == target.size()) return;
    
    sol(str, idx+1, target);
    
    string next_str = str + target[idx];
    if(count_menu.find(next_str) == count_menu.end()) {
        menu_list[next_str.size()].push_back(next_str);
        count_menu[next_str] = 1;
    }
    else count_menu[next_str]++;
    sol(str + target[idx], idx+1, target);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    menu_list.resize(11);
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(), orders[i].end());
        sol("", 0, orders[i]);
    }
    for(int i=0;i<course.size();i++){
        int cnt = course[i];
        int max_cnt = -1;
        for(int k=0;k<menu_list[cnt].size();k++){
            if(count_menu[menu_list[cnt][k]] >= 2 && max_cnt < count_menu[menu_list[cnt][k]]){
                max_cnt = count_menu[menu_list[cnt][k]];
            }
        }
        for(int k=0;k<menu_list[cnt].size();k++){
            if(count_menu[menu_list[cnt][k]] >= 2 && count_menu[menu_list[cnt][k]] == max_cnt){
                answer.push_back(menu_list[cnt][k]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
