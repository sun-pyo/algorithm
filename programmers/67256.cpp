#include <string>
#include <vector>

using namespace std;

int abs(int a){
    if(a < 0) return -a;
    return a;
}

int distance(pair<int, int> a, pair<int, int> b){
    int res = 0;
    res += abs(a.first - b.first);
    res += abs(a.second - b.second);
    return res;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> map;
    map.resize(10);
    map[0] = make_pair(3,1);
    int cnt = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            map[cnt++] = make_pair(i, j); 
        }
    }
    pair<int, int> l_curr = make_pair(3,0);
    pair<int, int> r_curr = make_pair(3,2);
    
    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7) {
            l_curr = map[num];
            answer += "L";
        }
        else if(num == 3 || num == 6 || num == 9){
            r_curr = map[num];
            answer += "R";
        }
        else{
            int l_distance = distance(map[num], l_curr);
            int r_distance = distance(map[num], r_curr);
            if(l_distance < r_distance || (l_distance == r_distance && hand == "left")){
                l_curr = map[num];
                answer += "L";
            }
            else if(l_distance > r_distance || (l_distance == r_distance && hand == "right")){
                r_curr = map[num];
                answer += "R";
            }
        }
    }
    return answer;
}