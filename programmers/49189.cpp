#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int visit[20001] = {0,};

int bfs(){
    queue<int> q;
    q.push(1);
    int curr, next, max_dist = 0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(visit[curr] > max_dist) max_dist = visit[curr];
        for(int i=0;i<graph[curr].size();i++){
            next = graph[curr][i];
            if(visit[next] == 0 && next != 1){
                visit[next] = visit[curr] + 1;
                q.push(next);
            }
        }
    }
    return max_dist;
}   

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int first, second;
    graph.resize(n+1);
    for(vector<int> temp : edge){
        first = temp[0];
        second = temp[1];
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    int max_dist = bfs();
    for(int i=1;i<=n;i++){
        if(visit[i] == max_dist) answer++;
    }
    return answer;
}