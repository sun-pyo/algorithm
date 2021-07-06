#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, L;
    vector<int> arr;
    cin>>N>>L;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer=0;
    double last=0;
    for(int i=0;i<arr.size();i++){
        while(last < arr[i] + 0.5){
            answer++;
            if(last < arr[i] - 0.5) last = arr[i] - 0.5 + L;
            else last += L;
        }
    }
    cout<<answer;
}