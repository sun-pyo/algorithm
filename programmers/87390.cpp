#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int x, y, num;
    for(long long i=left;i<=right;i++){
        x = i%n;
        y = i/n;
        num = max(x, y) + 1;
        answer.push_back(num);
    }
    return answer;
}