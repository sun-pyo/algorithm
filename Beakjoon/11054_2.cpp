#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int left_DP[1001];
int right_DP[1001];

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
        left_DP[i] = 1;
        right_DP[i] = 1;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(A[j] < A[i]){
                left_DP[i] = max(left_DP[j]+1, left_DP[i]);
            }
        }
    }

    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=i;j--){
            if(A[j] < A[i]){
                right_DP[i] = max(right_DP[j] + 1, right_DP[i]);
            }
        }
    }

    int answer = 0;
    for(int i=0;i<N;i++){
        if(answer < (left_DP[i] + right_DP[i]))
            answer = left_DP[i] + right_DP[i];
    }
    
    cout<<--answer;
}