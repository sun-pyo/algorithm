#include <iostream>
#include <vector>

using namespace std;

long long DP[36] = {0,};

int main(){
    int n;
    long long sum;
    cin>>n;
    DP[0] = 1;
    for(int i=1;i<=n;i++){
        sum = 0;
        for(int j=0;j<i;j++){
            sum += DP[j]*DP[i-j-1];
        }
        DP[i] = sum;
    }
    cout<<DP[n];
}