#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int H, W, num;
    cin>>H>>W;
    vector<int> arr;
    for(int i=0;i<W;i++){
        cin>>num;
        if(num > H) num = H;
        arr.push_back(num);
    }

    int answer = 0, max_l, max_r, h;
    for(int i=1;i<W-1;i++){
        max_l = arr[i];
        max_r = arr[i];
        for(int l=i-1;l>=0;l--){
            if(max_l < arr[l]) max_l = arr[l];
        }
        for(int r=i+1;r<W;r++){
            if(max_r < arr[r]) max_r = arr[r];
        }
        h = min(max_l, max_r);
        if(h - arr[i] > 0) answer += h - arr[i];
    }
    cout<<answer;
}