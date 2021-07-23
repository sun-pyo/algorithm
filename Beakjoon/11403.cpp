#include <vector>
#include <iostream>

using namespace std;

vector<int> edge[100];
int N;

vector<int> dfs(int start){
    vector<int> st;
    vector<int> visit(N, 0);
    st.push_back(start);
    int curr, next;
    while(!st.empty()){
        curr = st.back();
        st.pop_back();
        for(int i=0;i<edge[curr].size();i++){
            next = edge[curr][i];
            if(visit[next] == 0){
                visit[next] = 1;
                st.push_back(next);
            }
        }
    }
    return visit;
}

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int num;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num;
            if(num == 1) edge[i].push_back(j);
        }
    }

    vector<int> temp;
    for(int i=0;i<N;i++){
        temp = dfs(i);
        print(temp);
    }
}