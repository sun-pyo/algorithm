#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[10000];
int time_arr[10000];
int result[10000] = {0,};

int main(){
    int N, time, next, curr, inDegreeCount, answer=0;
    vector<vector<int>> next_node;
    cin>>N;
    next_node.resize(N);
    for(int i=0;i<N;i++){
        cin>>time>>inDegreeCount;
        for(int j=0;j<inDegreeCount;j++){
            cin>>next;
            next_node[next-1].push_back(i);
        }
        inDegree[i] = inDegreeCount;
        time_arr[i] = time;
    }
    queue<int> q;
    for(int i=0;i<N;i++){
        if(inDegree[i] == 0) {
            q.push(i);
            result[i] = time_arr[i];
            answer = max(answer, result[next]);
        } 
    }

    for(int i=0;i<N;i++){
        curr = q.front();
        q.pop();
        for(int next : next_node[curr]){
            inDegree[next]--;
            result[next] = max(result[next], result[curr] + time_arr[next]);
            answer = max(answer, result[next]);
            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }
    cout<<answer<<"\n";
}