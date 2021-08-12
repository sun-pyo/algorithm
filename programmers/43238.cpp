#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)times.back()*n;
    long long mid, sum;
    answer = right;
    while(left<=right){
        mid = (left + right)/2;
        sum = 0;
        for(long long time : times){
            sum += mid/time;
        }
        if(n>sum){
            left = mid + 1;
        }
        else {
            if(answer > mid) answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}