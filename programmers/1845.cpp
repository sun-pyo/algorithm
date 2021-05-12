#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    vector<int> check;
    check.resize(200001);
    int answer = 0;
    for(int i=0;i<nums.size();i++){
        if(check[nums[i]] == 0) {
            check[nums[i]] = 1;
            answer++;
        }
    }
    if(answer > nums.size()/2) answer = nums.size()/2;
    return answer;
}