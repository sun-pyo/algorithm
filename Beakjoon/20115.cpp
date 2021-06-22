#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int N;
    vector<double> arr;
    cin>>N;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<N-1;i++){
        arr[arr.size()-1] += (double)arr[i]/2;
    }
    cout<<arr.back()<<"\n";
}