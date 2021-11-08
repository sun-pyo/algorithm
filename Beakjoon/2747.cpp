#include <iostream>

using namespace std;

int fibonacci(int num){
    if(num == 0) return 0;
    if(num == 1) return 1;
    return fibonacci(num-1) + fibonacci(num-2);
}

int DP[45] = {0,};

int main(){
    int n;
    DP[1] = 1;
    cin>>n;
    for(int i=2;i<=n;i++){
        DP[i] = DP[i-1] + DP[i-2];
    }    
    cout<<DP[n];
}