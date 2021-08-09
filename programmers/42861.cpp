#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
vector<int> parent;

int find(int x){
    if(parent[x] == x) return x;
    return find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool is_cycle(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int node1, node2, answer = 0;
    parent.resize(n);
    vector<int> visit(n, 0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);
    for(vector<int> cost : costs){
        node1 = cost[0];
        node2 = cost[1];
        if(is_cycle(node1, node2)) continue;
        Union(node1, node2);
        answer += cost[2];
    }
    return answer;
}