#include <string>
#include <vector>

using namespace std;

int rotation(vector<vector<int>> &map, vector<int> q){
    int x1 = q[0] - 1;
    int y1 = q[1] - 1;
    int x2 = q[2] - 1;
    int y2 = q[3] - 1;
    int curr, next = map[x1][y1];
    int min = next;
    for(int y=y1+1;y<=y2;y++){
        curr = map[x1][y];
        if(min > curr) min = curr;
        map[x1][y] = next;
        next = curr;
    }
    for(int x=x1+1;x<=x2;x++){
        curr = map[x][y2];
        if(min > curr) min = curr;
        map[x][y2] = next;
        next = curr;
    }
    for(int y=y2-1;y>=y1;y--){
        curr = map[x2][y];
        if(min > curr) min = curr;
        map[x2][y] = next;
        next = curr;
    }
    for(int x=x2-1;x>=x1;x--){
        curr = map[x][y1];
        if(min > curr) min = curr;
        map[x][y1] = next;
        next = curr;
    }
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map;
    map.resize(rows);
    int cnt = 1;
    for(int row=0;row<rows;row++){
        map[row].resize(columns);
        for(int col=0;col<columns;col++){
            map[row][col] = cnt++;
        }
    }
    for(int i=0;i<queries.size();i++){
        answer.push_back(rotation(map, queries[i]));
    }
    return answer;
}