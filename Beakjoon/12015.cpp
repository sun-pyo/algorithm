#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    vector<int> arr;
    vector<int> arr2;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }

    arr2.push_back(arr[0]);
    for(int i=1;i<N;i++){
        if(arr2.back() < arr[i]){
            arr2.push_back(arr[i]);
        }
        else if(arr2.back() > arr[i]){
            int start = 0;
            int end = arr2.size();
            int mid;
            while(start<end){
                mid = (start+end)/2;
                
                if(arr2[mid] < arr[i]){
                    start = mid + 1;
                }
                else{
                    end = mid;
                }
            }
            arr2[end] = arr[i];
        }
    }
    cout<<arr2.size();

}