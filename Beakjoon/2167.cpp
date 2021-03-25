#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    vector<vector<int>> arr;

    cin>>N>>M;
    arr.resize(N);
    for(int i=0;i<N;i++){
        arr[i].resize(M);
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }

    cin>>K;
    int i, j, x, y;
    for(int k=0;k<K;k++){
        int sum = 0;
        cin>>i>>j>>x>>y;
        for(int r=i;r<=x;r++){
            for(int c=j;c<=y;c++){
                sum += arr[r-1][c-1];
            }
        }
        cout<<sum<<"\n";
    }

}