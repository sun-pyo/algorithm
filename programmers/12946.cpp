#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int mid, int to, vector<vector<int>> &answer){
    if(n == 1){
        answer.push_back({from, to});
        return;
    }
    hanoi(n-1, from, to, mid, answer);
    answer.push_back({from, to});
    hanoi(n-1, mid, from, to, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);
    return answer;
}