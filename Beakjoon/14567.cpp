#include <vector>
#include <iostream>

using namespace std;

int visit[1001];
vector<vector<int>> graph;

void dfs(int start){
    vector<int> st;
    st.push_back(start);
    int curr;
    while(!st.empty()){
        curr = st.back();
        st.pop_back();
        if(visit[curr] == 0) visit[curr] = 1;
        for(int i=0;i<graph[curr].size();i++){
            int next = graph[curr][i];
            if(visit[curr] + 1 > visit[next]){
                visit[next] = visit[curr] + 1;
                st.push_back(next);
            }
        }
    }
}

int main(){
    int N, M, num1, num2;
    cin>>N>>M;
    graph.resize(N+1);
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        graph[num1].push_back(num2);
    }

    for(int i=1;i<=N;i++){
        dfs(i);
    }

    for(int i=1;i<=N;i++){
        cout<<visit[i]<<" ";
    }
}