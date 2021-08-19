#include <string>
#include <vector>

#define INF 19900001

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int dist[201][201];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    int c, d, f;
    for(vector<int> temp : fares){
        c = temp[0];
        d = temp[1];
        f = temp[2];
        dist[c][d] = f;
        dist[d][c] = f;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    answer = dist[s][1] + dist[1][a] + dist[1][b];
    for(int i=2;i<=n;i++){
        if(dist[s][i] + dist[i][a] + dist[i][b] < answer) answer = dist[s][i] + dist[i][a] + dist[i][b];
    }
    
    return answer;
}