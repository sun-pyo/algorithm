#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[100001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin>>N>>K;

    int start = N;
    visit[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == K) break;
        if(curr+1 <= 100000 && curr < K && visit[curr+1] == 0){
            visit[curr+1] = visit[curr] + 1;
            q.push(curr+1);
        }
        if(curr-1 >= 0 && visit[curr-1] == 0){
            visit[curr-1] = visit[curr] + 1;
            q.push(curr-1);
        }
        if(curr*2 <= 100000 && curr < K && visit[curr*2] == 0){
            visit[curr*2] = visit[curr] + 1;
            q.push(curr*2);
        }

    }

    cout<<visit[K] - 1;

}