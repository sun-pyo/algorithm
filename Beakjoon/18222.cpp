#include <iostream>
#include <math.h>

using namespace std;

int solution(long long k){
    if(k == 1) return 0;
    if(k == 2) return 1;
    long long  n = 1;
    while(pow(2, n) < k) n++;
    n = pow(2, n-1);
    return 1 - solution(k - n);
}

int main(){
    long long k;
    cin>>k;
    cout<<solution(k);
}