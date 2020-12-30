#include <iostream>
#include <cstdio>

using namespace std;

int DP[2][100001];
int map[2][100001];

int main(){
    int T, n, i, j, k, t;
    scanf("%d",&T);
    for(t=0;t<T;t++){
        fill(&DP[0][0], &DP[1][100001], 0);
        scanf("%d",&n);
        for(j=0;j<2;j++){
            for(k=1;k<=n;k++)
                scanf("%d",&map[j][k]);
        }

        DP[0][1] = map[0][1];
        DP[1][1] =  map[1][1];
        
        for(j=2;j<=n;j++){
            DP[0][j] = max(DP[1][j-1],DP[1][j-2]) + map[0][j];
            DP[1][j] = max(DP[0][j-1],DP[0][j-2]) + map[1][j];
        }
        
        printf("%d\n", max(DP[0][n], DP[1][n]));
    }
}