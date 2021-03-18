#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size()-1;
    int sum;
    for(int i=right;i>=left;i--){
        sum = people[i];
        while(sum + people[left] <= limit){
            sum += people[left];
            left++;
        }
        answer++;
    }
    return answer;
}