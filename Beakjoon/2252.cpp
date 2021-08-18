#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topology_sort(vector<int> indegree, vector<vector<int>> graph){
    vector<int> result;
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0) q.push(i);
    }
    int curr;
    while(!q.empty()){
        curr = q.front();
        result.push_back(curr);
        q.pop();
        for(int next : graph[curr]){
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    return result;
}

int main(){
    int N, M, A, B;
    cin>>N>>M;
    vector<int> indegree(N, 0);
    vector<vector<int>> graph(N);
    vector<int> answer;
    for(int i=0;i<M;i++){
        cin>>A>>B;
        A--;
        B--;
        graph[A].push_back(B);
        indegree[B]++;
    }
    answer = topology_sort(indegree, graph);
    for(int num : answer){
        cout<<++num<<" ";
    }
}