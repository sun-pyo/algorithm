#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;

int dfs(int start_x, int start_y){
    vector<pair<int, int>> st;
    st.push_back(make_pair(start_x, start_y));
    int x, y, next_x, next_y, cnt = 0;
    while(!st.empty()){
        x = st.back().first;
        y = st.back().second;
        st.pop_back();
        if(map[y][x] == 0) continue;
        map[y][x] = 0;
        cnt++;
        for(int i=0;i<4;i++){
            next_x = x + dx[i];
            next_y = y + dy[i];
            if(next_x >= 0 && next_x < M && next_y >=0 && next_y < N && map[next_y][next_x] == 1){
                st.push_back(make_pair(next_x, next_y));
            }
        }
    }
    return cnt;
}

int main(){
    cin>>N>>M;
    map.resize(N);
    for(int i=0;i<N;i++){
        map[i].resize(M);
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    int cnt = 0, max_ = 0, res;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 1){
                res = dfs(j, i);
                cnt++;
                if(max_ < res) max_ = res;
            }
        }
    }
    cout<<cnt<<"\n"<<max_;
}