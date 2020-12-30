#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;


int visited[1001];
vector<int> s;
queue<int> q;
int graph[1001][1001];
int N, M, V;

void dfs(int v){
    s.push_back(v);
    int b;
    while(!s.empty()){
        b = s.back();
        s.pop_back();
        if(visited[b] != 1){
            visited[b] = 1;
            printf("%d ",b);
            for(int i=N;i>0;i--){
                if(graph[b][i] == 1 && visited[i] != 1){
                    s.push_back(i);
                }
            }
        }
    }
}

void bfs(int v){
    q.push(v);
    int b;
    while(!q.empty()){
        b = q.front();
        q.pop();
        if(visited[b] != 1){
            visited[b] = 1;
            printf("%d ",b);
            for(int i=1;i<=N;i++){
                if(graph[b][i] == 1 && visited[i] != 1){
                    q.push(i);
                }
            }
        }
    }
}

int main(){
    int st, ed;
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        cin>>st>>ed;
        graph[st][ed] = 1;
        graph[ed][st] = 1;
    }
    dfs(V);
    fill(&visited[0], &visited[1001], 0 );
    printf("\n");
    bfs(V);
    
}