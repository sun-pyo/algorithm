#include <vector>

using namespace std;

vector<vector<int>> visit;
int X[] = {1,-1,0, 0};
int Y[] = {0, 0,1,-1};

int dfs(int start_x, int start_y, vector<vector<int>> &picture, int m, int n){
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(start_x, start_y));
    int color = picture[start_y][start_x];
    int res = 0;
    while(!stack.empty()){
        int x = stack.back().first;
        int y = stack.back().second;
        stack.pop_back();
        if(visit[y][x] == 0){
            visit[y][x] = 1;
            res++;
            for(int i=0;i<4;i++){
                int next_x = x + X[i];
                int next_y = y + Y[i];
                if(next_x >=0 && next_x < n && next_y >=0 && next_y < m && visit[next_y][next_x] == 0 && picture[next_y][next_x] == color){
                    stack.push_back(make_pair(next_x, next_y));
                }
            }
        }
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    visit.resize(m);
    for(int i=0;i<m;i++){
        visit[i].resize(n);
        for(int j=0;j<n;j++){
            if(picture[i][j] == 0){
                visit[i][j] = 1;
            }
            else{
                visit[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j] == 0){
                number_of_area++;
                int size = dfs(j, i, picture, m, n);
                if(size > max_size_of_one_area) max_size_of_one_area = size;
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}