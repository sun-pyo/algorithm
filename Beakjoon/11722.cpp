#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int DP[1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> A;
    int N, num;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>num;
        A.push_back(num);
        DP[i] = 1;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(A[i] < A[j]){
                DP[i] = max(DP[j]+ 1, DP[i]);
            }
        }
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        if(DP[i] > answer)
            answer = DP[i];
    }
    cout<<answer;
}