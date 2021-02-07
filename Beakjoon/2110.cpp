#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C, num;
    cin>>N>>C;
    vector<int> arr;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    int start = 1;
    int end = arr.back() - arr[0];
    int answer = 0;
    while(start<=end){
        int mid = (start + end)/2;
        int c = 1;
        int last = arr[0];
        for(int i=1;i<N;i++){
            if(mid <= arr[i] - last){
                last = arr[i];
                c++;
            }
        }   

        if(c >= C){
            start = mid + 1;
            answer = mid;
        }
        else{
            end = mid - 1;
        }
    }

    cout<<answer;
}