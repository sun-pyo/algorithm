#include <cstdio>
#include <iostream>

using namespace std;

int DP[10001];
int map[10001];

int main(){
    int n, min_num, max_num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&map[i]);
    
    DP[1] = map[1];
    if(n > 1)
        DP[2] = map[1] + map[2];

    for(int i=3;i<=n;i++){
        DP[i] = max(DP[i-1], max(DP[i-2]+map[i], DP[i-3]+map[i-1]+map[i]));
    }

    printf("%d", DP[n]);
}