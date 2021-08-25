#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> relationship;
vector<int> visit;

int dfs(int start){
    vector<int> stack;
    stack.push_back(start);
    int curr, visit_count = 0;
    while(!stack.empty()){
        curr = stack.back();
        stack.pop_back();
        if(visit[curr] != 0) continue;
        visit[curr] = 1;
        visit_count++;
        for(int next : relationship[curr]){
            if(visit[next] == 0){
                stack.push_back(next);
            }
        }
    }
    return visit_count;
}

int main(){
    int N, M, K;
    int num1, num2, idx, answer=0, count=0;
    cin>>N>>M>>K;
    vector<pair<int ,int>> cost(N+1);
    relationship.resize(N+1);
    visit.resize(N+1);
    
    for(int i=1;i<=N;i++){
        cin>>cost[i].first;
        cost[i].second = i;
        visit[i] = 0;
    }

    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        relationship[num1].push_back(num2);
        relationship[num2].push_back(num1);
    }
    sort(cost.begin(), cost.end());
    for(int i=1;i<=N;i++){
        idx = cost[i].second;
        if(visit[idx] == 0){
            count += dfs(idx);
            answer += cost[i].first;
        }
    }
    if(count != N || answer > K)  cout<<"Oh no\n";
    else cout<<answer;

}