#include <vector>
#include <iostream>

using namespace std;

int dist[501][501];

void Floyd(int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(dist[j][i] + dist[i][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, num;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>dist[i][j];
        }
    }
    Floyd(N);
    int A,B,C;
    for(int i=0;i<M;i++){
        cin>>A>>B>>C;
        if(dist[A][B] <= C){
            cout<<"Enjoy other party\n";
        }
        else cout<<"Stay here\n";
    }

}