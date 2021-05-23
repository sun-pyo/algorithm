#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<vector<int>> child;
vector<int> visit;
int N;

int dfs(int start){
    vector<int> st;
    st.push_back(start);
    int curr, next, cnt = 0;
    while(!st.empty()){
        curr = st.back();
        st.pop_back();
        if(visit[curr] == 1) continue;
        visit[curr] = 1;
        if(child[curr].empty()) cnt++;
        else{
            for(int i=0;i<child[curr].size();i++){
                next = child[curr][i];
                if(visit[next] == 0) st.push_back(next);
            }
        }
    }
    return cnt;
}

int main(){
    int num, del_num, root_node;
    cin>>N;
    
    parents.resize(N);
    child.resize(N);
    visit.resize(N);

    for(int i=0;i<N;i++){
        cin>>num;
        parents[i] = num;
        if(num != -1 && num >=0 && num < N) child[num].push_back(i);
        else root_node = i;
    }
    cin>>del_num;
    if(del_num == root_node){
        cout<<"0";
        return 0;
    }
    else if(del_num >= 0 && del_num < N){
        num = parents[del_num];
        for(int i=0;i<child[num].size();i++){
            if(del_num == child[num][i]) child[num].erase(child[num].begin() + i);
        }
    }

    int res;
    res = dfs(root_node);
    cout<<res;
}   

