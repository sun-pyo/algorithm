#include <stdio.h>
#include <vector>

using namespace std;

vector<int> map;
vector<int> visit;
int solution(int start){
    int count = 0;
    int curr = start;
    vector<int> stack;
    while(!visit[curr]){
        stack.push_back(curr);
        visit[curr] = 1;
        curr = map[curr];
    }
    for(int i=0;i<stack.size();i++){
        if(stack[i] == curr){
            break;
        }
        count++;
    }
    return count;
}

int main(){
    int T, n;
    scanf("%d", &T);

    for(int t=0;t<T;t++){
        scanf("%d", &n);
        map.resize(n+1);
        visit.resize(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d", &map[i]);
        }
        int answer = 0;
        for(int i=1;i<=n;i++){
            answer += solution(i);
        }

        printf("%d\n", answer);
        visit.clear();
        map.clear();
    }
}