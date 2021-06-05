#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N = 2, sum = 0;
    int num;
    cin>>M;

    while(true){
        num = N;
        while(num%5 == 0){
            sum++;
            num/=5;
        }
        if(sum == M){
            cout<<N<<"\n";
            return 0;
        }
        else if(sum > M){
            cout<<"-1\n";
            return 0;
        }
        N++;
    }
    
}