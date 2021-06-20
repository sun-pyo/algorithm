#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<long long> arr;
    cin>>N;
    long long m, num;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int r = N-1;
    m = 0;
    if(N%2 != 0) r--;
    for(int l=0;l<N/2;l++){
        if(m < arr[l] + arr[r]) m = arr[l] + arr[r];
        r--;
    }
    if(N%2 != 0 && m < arr.back()) m = arr.back();
    cout<<m;
}