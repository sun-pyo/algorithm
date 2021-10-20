#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<pair<int, int>>> graph;
int answer = 0;

int solution(int node){
    int w, child, max_len = 0, len = 0, total_len = 0;
    priority_queue<int> len_pq;
    
    for(int i=0;i<graph[node].size();i++){
        child = graph[node][i].first;
        w = graph[node][i].second;
        len = solution(child) + w;
        len_pq.push(len);
        max_len = max(max_len, len);
    }
    for(int i=0;i<2;i++){
        if(!len_pq.empty()){
            total_len += len_pq.top();
            len_pq.pop();
        }
    }
    answer = max(answer ,total_len);
    return max_len;
}

int main(){
    int N, par, child, w;
    cin>>N;
    graph.resize(N);
    for(int i=0;i<N-1;i++){
        cin>>par>>child>>w;
        par--;
        child--;
        graph[par].push_back({child, w});
    }
    solution(0);
    cout<<answer<<"\n";
}