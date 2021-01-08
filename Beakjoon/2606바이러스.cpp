#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector<int> node[100];
int visit[100];

int dfs(int start){
    int count = 0;
    vector<int> stack;
    stack.push_back(start);
    while(!stack.empty()){
        int n = stack.back();
        stack.pop_back();
        visit[n] = 1;
        count++;
        for(int i=0;i<node[n].size();i++){
            int next = node[n][i];
            if(visit[next] == 0){
                visit[next] = 1;
                stack.push_back(next);
            }
        }
    }

    return count; 
}


int main(){
    int N, M, a, b;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int answer = dfs(1);
    printf("%d",answer-1);
    
}