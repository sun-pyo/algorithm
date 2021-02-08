#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int T, N, M;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N>>M;
        int DP[30][30] = {0,};
        for(int i=0;i<N;i++){
            for(int j=i;j<M-(N-1-i);j++){
                if(i==0){
                    DP[i][j] = 1;
                }
                else{
                    for(int k=i-1;k<j;k++){
                        DP[i][j] += DP[i-1][k];
                    }
                }
            }
        }
        int answer = 0;
        for(int i=N-1;i<M;i++){
            answer += DP[N-1][i];
        }
        cout<<answer<<"\n";
    }

}