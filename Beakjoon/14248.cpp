#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> visit;
int dfs(int start){
    vector<int> st;
    int cnt = 0;
    st.push_back(start);
    int curr;
    while(!st.empty()){
        curr = st.back();
        st.pop_back();
        if(visit[curr] == 1) continue;
        visit[curr] = 1;
        cnt++;
        for(int i=0;i<map[curr].size();i++){
            int next = map[curr][i];
            if(visit[next] == 0){
                st.push_back(next);
            }
        }
    }
    return cnt;
}

int main(){
    int N;
    cin>>N;
    map.resize(N+1);
    visit.resize(N+1);
    int num;
    for(int i=1;i<=N;i++){
        cin>>num;
        if(i+num <= N) map[i].push_back(i+num);
        if(i-num >= 1) map[i].push_back(i-num);
    }
    int start;
    cin>>start;

    cout<<dfs(start);
}