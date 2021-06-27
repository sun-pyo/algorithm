#include <vector>
#include <iostream>

using namespace std;

int DP[1024][1024];
int map[1024][1024];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>DP[i][j];
            if(i > 0){
                DP[i][j] += DP[i-1][j];
            }
            if(j > 0){
                DP[i][j] += DP[i][j-1];
                if(i > 0){
                    DP[i][j] -= DP[i-1][j-1];
                }
            }
        }
    }
    int x1, y1, x2, y2;
    long long answer = 0;
    for(int i=0;i<M;i++){
        cin>>y1>>x1>>y2>>x2;
        x1--;
        y1--;
        x2--;
        y2--;
        answer = DP[y2][x2];
        if(x1 > 0){
            answer -= DP[y2][x1-1];
        }
        if(y1 > 0){
            answer -= DP[y1-1][x2];
            if(x1 > 0) answer += DP[y1-1][x1-1];
        }
        cout<<answer<<"\n";
    }
}