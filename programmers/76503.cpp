#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> visit;
long long dfs(int idx, int pre_idx, vector<long long> &a){
    long long res = 0;
    visit[idx] = 1;
    for(int i=0;i<map[idx].size();i++){
        int next = map[idx][i];
        if(visit[next] == 0){
            res += dfs(next, idx, a);
        }
    }  
    long long num = a[idx];
    a[pre_idx] += num;
    a[idx] = 0;
    if(num >= 0) res += num;
    else res += -num;
    
    return res;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    long long sum = 0;
    vector<long long> new_a;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        new_a.push_back(a[i]);
    }
    if(sum != 0) return -1;
    int size = a.size();
    visit.resize(size);
    map.resize(size);
    for(int i=0;i<edges.size();i++){
        map[edges[i][0]].push_back(edges[i][1]);
        map[edges[i][1]].push_back(edges[i][0]);
    }
    answer = dfs(0, 0, new_a);
    return answer;
}