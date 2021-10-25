#include <iostream>
#include <vector>

using namespace std;

int map[50][50] = {0,};
vector<pair<int, int>> home, chicken;
vector<vector<int>> all;
vector<int> temp;
int N, M;

int get_distance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void choose_chicken(int idx, int count){
    if(count == M){
        all.push_back(temp);
        return;
    }
    else if(idx == chicken.size()){
        return;
    }
    choose_chicken(idx+1, count);
    temp.push_back(idx);
    choose_chicken(idx+1, count+1);
    temp.pop_back();
    return;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j] == 1) home.push_back({j, i});
            else if(map[i][j] == 2) chicken.push_back({j, i});
        }
    }
    choose_chicken(0, 0);
    int h_x, h_y, c_x, c_y, sum, min_dist, answer=50000;
    for(int i=0;i<all.size();i++){
        sum = 0;
        for(int k=0;k<home.size();k++){
            h_x = home[k].first;
            h_y = home[k].second;
            min_dist = 100;
            for(int m=0;m<M;m++){
                c_x = chicken[all[i][m]].first;
                c_y = chicken[all[i][m]].second;
                min_dist = min(min_dist, get_distance(h_x, h_y, c_x, c_y));
            }
            sum += min_dist;
        }
        answer = min(answer, sum);
    }
    cout<<answer<<"\n";
}