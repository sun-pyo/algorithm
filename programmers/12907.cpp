#include <string>
#include <vector>

using namespace std;

int DP[100001] = {0,};

int solution(int n, vector<int> money) {
    int answer = 0, m;
    for(int j=0;j<money.size();j++){
        m = money[j];
        DP[m] += 1;
        for(int i=m+1;i<=n;i++){
            DP[i] += DP[i-m]%1000000007;
        }
    }
    answer = DP[n]%1000000007;
    return answer;
}