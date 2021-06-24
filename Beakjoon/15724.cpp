#include <vector>
#include <iostream>

using namespace std;

int DP[1025][1025];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>num;
            DP[i][j] = num + DP[i][j-1]; 
        }
    }
    int K, x1, x2, y1, y2, answer;
    cin>>K;
    for(int k=0;k<K;k++){
        cin>>y1>>x1>>y2>>x2;
        answer = 0;
        for(int y=y1;y<=y2;y++){
            answer += DP[y][x2] - DP[y][x1-1];
        }
        cout<<answer<<"\n";
    }

}