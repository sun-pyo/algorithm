#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int edge[1001];
int visit[1001];

int dfs(int start){
    vector<int> stack;
    stack.push_back(start);
    int next;
    while(!stack.empty()){
        int curr = stack.back();
        stack.pop_back();
        visit[curr] = 1;

        next = edge[curr];   
        if(visit[next] == 1){
            return 1;
        }
        else{
            stack.push_back(next);
        }
    }
    return 0;
}

int main(){
    int T, N;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        memset(visit, 0, sizeof(visit));
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d", &edge[i]);
        }

        int answer = 0;
        for(int i=1;i<=N;i++){
            if(visit[i] == 0)
                answer += dfs(i);
        }  

        printf("%d\n", answer);
    }
}