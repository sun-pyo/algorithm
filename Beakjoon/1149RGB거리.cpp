#include <stdio.h>
#include <vector>


using namespace std;

vector<int> RGB[1000];
int DP[1000][3];


int main(){
    int N, r, g, b;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d %d %d", &r, &g, &b);
        RGB[i].push_back(r);
        RGB[i].push_back(g);
        RGB[i].push_back(b);
    }

    DP[0][0] = RGB[0][0];
    DP[0][1] = RGB[0][1];
    DP[0][2] = RGB[0][2];

    for(int i = 1;i<N;i++){
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + RGB[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + RGB[i][1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + RGB[i][2];
    }
    int answer = min(DP[N-1][0], min(DP[N-1][1], DP[N-1][2]));
    printf("%d",answer);
}