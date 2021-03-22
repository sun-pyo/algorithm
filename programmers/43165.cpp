#include <string>
#include <vector>

using namespace std;

int sol(int idx, int sum, vector<int> visit, vector<int> numbers, int target){
    if(sum == target) return 1;
    else if(idx == numbers.size()) return 0;
    int res = 0;
    // visit[idx] = 0
    res += sol(idx+1, sum, visit, numbers, target);
    if(sum-2*numbers[idx] >= target){
        visit[idx] = 1;
        res += sol(idx+1, sum - 2*numbers[idx], visit, numbers, target);
    }
    return res;
}

int solution(vector<int> numbers, int target) {
    vector<int> visit;
    visit.resize(numbers.size());
    int sum = 0;
    for(int i=0;i<numbers.size();i++) sum += numbers[i]; 
    int answer = sol(0,sum, visit, numbers, target);
    return answer;
}