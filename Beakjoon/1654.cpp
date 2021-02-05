#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, num;
    cin>>K>>N;

    vector<int> lan;
    for(int i=0;i<K;i++){
        cin>>num;
        lan.push_back(num);
    }

    sort(lan.begin(), lan.end());

    long long left = 1;
    long long right = lan.back();
    int answer = 0;
    while(left <= right){
        long long mid = (left+right)/2;
        if(mid == 0) break;
        int total = 0;

        for(int i=0;i<K;i++){
            total += (lan[i]/mid);
        }

        if(total >= N){
            answer = mid;
            left = mid + 1; 
        }
        else{
            right = mid - 1;
        }
    }

    cout<<answer;

}