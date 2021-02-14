#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int DP[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    vector<int> arr;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }

    int answer = arr[0];
    DP[0] = arr[0];
    for(int i=1;i<N;i++){
        DP[i] = max(DP[i-1] + arr[i], arr[i]);
        if(DP[i] > answer) answer = DP[i];
    }
    cout<<answer;

    
}