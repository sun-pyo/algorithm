#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string, int> index;
vector<vector<string>> edge;

int bfs(string begin, string target){
    queue<string> q;
    q.push(begin);
    string curr, next;
    int idx, next_idx;
    int visit[51] = {0,};
    while(!q.empty()){
        curr = q.front();
        idx = index[curr];
        q.pop();
        if(curr == target) return visit[idx];
        for(int i=0;i<edge[idx].size();i++){
            next = edge[idx][i];
            next_idx = index[next];
            if(visit[next_idx] == 0){
                visit[next_idx] = visit[idx] + 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, cnt;
    index[begin] = 0;
    edge.resize(words.size()+1);
    for(int i=0;i<words.size();i++){
        index[words[i]] = i+1;
    }
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            cnt = 0;
            for(int k=0;k<words[i].size();k++){
                if(words[i][k] == words[j][k]) cnt++;
            }
            if(cnt == words[i].size()-1){
                edge[index[words[i]]].push_back(words[j]);
                edge[index[words[j]]].push_back(words[i]);
            }
        }
    }
    for(string word : words){
        cnt = 0;
        for(int i=0;i<begin.size();i++){
            if(begin[i] == word[i]) cnt++;
        }
        if(cnt == begin.size()-1){
            edge[index[begin]].push_back(word);
        }
    }
    answer = bfs(begin, target);
    return answer;
}