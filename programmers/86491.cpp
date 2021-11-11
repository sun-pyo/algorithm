#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, temp, w, h, max_w=-1, max_h=-1;
    for(int i=0;i<sizes.size();i++){
        w = sizes[i][0];
        h = sizes[i][1];
        if(h > w){
            temp = w;
            w = h;
            h = temp;
        }
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }
    answer = max_w * max_h;
    return answer;
}