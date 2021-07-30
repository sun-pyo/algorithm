#include <string>
#include <vector>

using namespace std;

int visit[200] = {0,};

void dfs(vector<vector<int>> &computers, int start){
    vector<int> stack;
    stack.push_back(start);
    int curr;
    while(!stack.empty()){
        curr = stack.back();
        stack.pop_back();
        for(int next=0;next<computers.size();next++){
            if(next!=curr && visit[next] == 0 && computers[curr][next] == 1){
                stack.push_back(next);
                visit[next] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        if(visit[i] == 0){
            dfs(computers, i);
            answer++;
        }        
    }
    return answer;
}