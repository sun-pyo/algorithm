#include <vector>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int dist[101][101];

int main(){
    int N, M, a, b, sum, min_dist, answer_a, answer_b, answer_dist = 2000000000;
    cin>>N>>M;
    memset(dist, 0x1111, sizeof(dist));

    for(int i=0;i<M;i++){
        cin>>a>>b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            sum = 0;
            for(int k=1;k<=N;k++){
                if(k != i && k != j){
                    min_dist = min(dist[i][k], dist[j][k]);
                    sum += min_dist*2;
                }
            }
            if(answer_dist > sum){
                answer_dist = sum;
                answer_a = i;
                answer_b = j;
            }
        }
    }
    cout<<answer_a<<" "<<answer_b<<" "<<answer_dist<<"\n";
}