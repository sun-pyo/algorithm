#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    for(int i = h;i>0;i--){
        answer += w - ceil((double)w*i/h);
    }
    answer *= 2;
    return answer;
}