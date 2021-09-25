#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INF 2000000000

vector<vector<char>> map;
int max_answer = -INF, min_answer = INF, N;

int calculate(string s){
    int a, b;
    char cal;
    a = s[0] - '0';
    for(int i=1;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            b = s[i] - '0';
            if(cal == '+'){
                a = a + b;
            }
            else if(cal == '-'){
                a = a - b;
            }
            else if(cal == '*'){
                a = a * b;
            }
        }
        else{
            cal = s[i];
        }
    }
    return a;
}

void dfs(int x, int y, string route){
    if(x == N-1 && y == N-1){
        route += map[y][x];
        int num = calculate(route);
        if(max_answer < num) max_answer = num;
        if(min_answer > num) min_answer = num;
        return;
    }

    if(x+1 < N)
        dfs(x+1, y, route+map[y][x]);
    if(y+1 < N)
        dfs(x, y+1, route+map[y][x]);
}

int main(){
    cin>>N;
    map.resize(N);
    for(int i=0;i<N;i++){
        map[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    dfs(0, 0, "");
    cout<<max_answer<<" "<<min_answer<<"\n";
}