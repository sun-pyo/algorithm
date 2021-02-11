#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> DP[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    vector<int> A;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>num;
        A.push_back(num);
        DP[i].first = 1;
        DP[i].second = i;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[j] < A[i])
            {
                if(DP[j].first + 1 > DP[i].first){
                    DP[i].first = DP[j].first + 1;
                    DP[i].second = j;
                }
            }
        }
    }

    int len = 0;
    int idx;
    for(int i=0;i<N;i++){
        if(len <DP[i].first) {
            len = DP[i].first;
            idx = i;
        }
    }

    vector<int> result;
    for(int i=0;i<len;i++){
        num = A[idx];
        result.push_back(num);
        idx = DP[idx].second;
    }
    cout<<len<<"\n";
    while(!result.empty()){
        num = result.back();
        result.pop_back();
        cout<<num<<" ";
    }
}