#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int DP[5000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, num;
    vector<vector<int>> g;
    vector<pair<int, int>> height;
    cin>>N>>M;
    g.resize(N);
    for(int i=0;i<N;i++){
        cin>>num;
        height.push_back({num, i});
    }
    int first, second;
    for(int i=0;i<M;i++){
        cin>>first>>second;
        if(height[first-1].first > height[second-1].first){
            g[second-1].push_back(first-1);
        }
        else{
            g[first-1].push_back(second-1);
        }
    }
    sort(height.begin(), height.end());

    for(int i=N-1;i>=0;i--){
        num = height[i].second;
        if(g[num].empty()) {
            DP[num] = 1;
        }
        else{
            int max = 0;
            for(int j=0;j<g[num].size();j++){
                int next = g[num][j];
                if( max < DP[next]) max = DP[next];
            }
            DP[num] = max + 1;
        }
    }
    for(int i=0;i<N;i++){
        cout<<DP[i]<<"\n";
    }
}