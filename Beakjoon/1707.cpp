#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> visit;
vector<int> group;

bool dfs(int start){
    vector<int> stack;
    stack.push_back(start);
    group[start] = 1;
    while(!stack.empty()){
        int curr = stack.back();
        stack.pop_back();

        if(visit[curr] == 0){
            visit[curr] = 1;
            for(int i=0;i<edge[curr].size();i++){
                int next = edge[curr][i];
                if(group[next] == 0){
                    group[next] = -group[curr];
                }
                else if(group[next] == group[curr]){
                    return false;
                }
                if(visit[next] == 0){
                    stack.push_back(next);
                }
            }
        }
    }
    return true;

}


int main(){
    int K, V, E;
    int first, second;
    scanf("%d", &K);
    for(int t=0;t<K;t++){
        scanf("%d %d", &V, &E);
        
        edge.resize(V+1);
        visit.resize(V+1);
        group.resize(V+1);
        
        for(int i=0;i<E;i++){
            scanf("%d %d", &first, &second);
            edge[first].push_back(second);
            edge[second].push_back(first);
        }

        bool answer = true;
        for(int i=0;i<V;i++){
            if(visit[i] == 0) {
                answer = dfs(i);
                if(!answer) break;
            } 
        }

        if(!answer || V == 1){
            printf("NO\n");
        }else{
            printf("YES\n");
        }


        group.clear();
        edge.clear();
        visit.clear();
    }
}