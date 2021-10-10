#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int map[100][100] = {0,};
vector<pair<int, int>> item;
int N, M, A;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int solution(int x, int y, int target_x, int target_y){ 
    if(x == target_x && y == target_y) return 1;
    int res = 0;
    if(x+1 <= target_x && map[y][x+1] != -1)
        res += solution(x+1, y, target_x, target_y);
    if(y+1 <= target_y && map[y+1][x] != -1)
        res += solution(x, y+1, target_x, target_y);
    return res;
}

int main(){
    int n, m, a, B, y, x;
    cin>>n>>m>>a>>B;
    N = n;
    M = m;
    A = a;
    for(int i=0;i<a;i++){
        cin>>y>>x;
        y--;
        x--;
        map[y][x] = 1;
        item.push_back({x, y});
    }
    for(int i=0;i<B;i++){
        cin>>y>>x;
        y--;
        x--;
        map[y][x] = -1;
    }
    item.push_back({M-1, N-1});
    sort(item.begin(), item.end(), compare);
    int start_x = 0, start_y = 0, target_x, target_y, res, answer=1;
    for(int i=0;i<item.size();i++){
        target_x = item[i].first;
        target_y = item[i].second;
        res = solution(start_x, start_y, target_x, target_y);
        answer *= res;
        start_x = target_x;
        start_y = target_y;
    }
    cout<<answer<<"\n";
}