#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int topology_sort(int target, vector<vector<int>> edge, vector<int> time, vector<int> indegree){
    queue<int> q;
    vector<int> maxTime(edge.size(), 0);
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
            maxTime[i] = time[i];
        }
    }
    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(int next : edge[curr]){
            indegree[next]--;
            maxTime[next] = max(maxTime[next], maxTime[curr] + time[next]);
            if(indegree[next] == 0) q.push(next);
        }
    }
    return maxTime[target];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N, K, start, end, target, resultTime;;;
        cin>>N>>K;
        vector<vector<int>> edge;
        vector<int> time(N);
        vector<int> indegree(N);
        edge.resize(N);
        for(int i=0;i<N;i++){
            cin>>time[i];
        }
        for(int i=0;i<K;i++){
            cin>>start>>end;
            start--;
            end--;
            edge[start].push_back(end);
            indegree[end]++;
        }
        cin>>target;
        target--;
        resultTime = topology_sort(target, edge, time, indegree);
        cout<<resultTime<<"\n";
    }
}