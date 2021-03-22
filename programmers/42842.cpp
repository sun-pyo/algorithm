#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w;
    w = (((brown+4)/2) + sqrt((brown+4)*(brown+4)/4 - 4*(brown+yellow)))/2;
    int h = (brown + 4 - 2*w)/2;
    answer.push_back(w);
    answer.push_back(h);
    return answer;
}