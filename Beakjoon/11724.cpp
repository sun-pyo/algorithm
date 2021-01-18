#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> edge; 
vector<int> visit;

void dfs(int start){
    vector<int> stack;
    stack.push_back(start);
    while(!stack.empty()){
        int node = stack.back();
        stack.pop_back();
        if(visit[node] == 0){
            visit[node] = 1;
            for(int i=0;i<edge[node].size();i++){
                int next = edge[node][i];
                if(visit[next] == 0){
                    stack.push_back(next);
                }
            }
        }
    }
}

int main(){
    int N, M, num1, num2;
    scanf("%d %d", &N, &M);
    
    edge.resize(N+1);
    visit.resize(N+1);

    for(int i = 0;i<M;i++){
        scanf("%d %d",&num1, &num2);
        edge[num1].push_back(num2);
        edge[num2].push_back(num1);
    }
    int answer = 0;
    for(int i=1;i<=N;i++){
        if(visit[i] == 0){
            dfs(i);
            answer++;
        }
    }
    printf("%d",answer);
}