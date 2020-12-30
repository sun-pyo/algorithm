#include <iostream>

using namespace std;

int Answer, N, K, L;
int mine[50001];
long long dp[50001][101];

int main(int argc, char** argv)
{
	int T, test_case, i, num, j;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        fill(&mine[0],&mine[50001],0);
		fill(&dp[0][0], &dp[50001][101],0);
        Answer = 0;
        cin>>N>>K>>L;
        for(i=0;i<L;i++){
            cin>>num;
            mine[num] = 1;
        }
        for(i=1;i<=N;i++){
            if(mine[i]) continue;
            for(j=1;j<=K;j++){
                if(i-j<0) break;
                else if(i == j){
                    dp[i][j]++;
                    dp[i][0] += dp[i][j];
                }
                else
                {
                    dp[i][j] = dp[i-j][0]-dp[i-j][j];
                    dp[i][0] = (dp[i][0] + dp[i][j] +1000000009)%1000000009;
                }
            }
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << dp[N][0] << "\n";
	}

	return 0;
}