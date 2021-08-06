#include <string>
#include <vector>

using namespace std;

long long DP[60001] = {0,};

int solution(int n) {
    int answer = 0;
    DP[1] = 1;
    DP[2] = 2;
    for(int i=3;i<=n;i++){
        DP[i] = (DP[i-1] + DP[i-2])%1000000007;
    }
    answer = DP[n];
    return answer;
}