#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int DP[1001][1001] ={1,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    vector<int> A;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>num;
        A.push_back(num);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i] > A[j]){
                DP[i][j] = 1;
                for(int k=j-1;k>=0;k--){
                    if(A[k] < A[j]){
                        DP[i][j] = max(DP[i][k]+1, DP[i][j]);
                    }
                }
            }
        }
        for(int j=i+1;j<N;j++){
            if(A[i] > A[j]){
                DP[i][j] = 1;
                for(int k=i+1;k<j;k++){
                    if(A[k] > A[j]){
                        DP[i][j] = max(DP[i][k]+1, DP[i][j]);
                    }
                }
            }
        }

        int left=0, right=0;
        for(int j=0;j<i;j++){
            if(left < DP[i][j])
                left = DP[i][j];
        }
        for(int j=i+1;j<N;j++){
            if(right<DP[i][j])
                right = DP[i][j];
        }
        DP[i][i] = left + right + 1;
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        if(DP[i][i] > answer)
            answer = DP[i][i];
    }
    cout<<answer;
}