#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int b_search(int num, int start, int end){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid] == num) break;

        if(arr[mid] < num){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return mid;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
        
    }

    cin>>M;
    vector<int> Marr;
    sort(arr.begin(), arr.end());
    for(int i=0;i<M;i++){
        cin>>num;
        int start = 0;
        int end = arr.size()-1;
        int mid;
        mid = b_search(num, start, end);

        if(arr[mid] == num){
            int left = mid, right = mid;
            while(left>=0 && arr[left] == num){
                if(left == 0) break;
                left = b_search(num, 0, left-1);
            }
            while(right<arr.size() && arr[right] == num){
                if(right == arr.size()-1) break;
                right = b_search(num, right+1, arr.size()-1);
            }
            if(arr[left] != num) left++;
            if(arr[right] != num) right--;
            cout<<right-left+1<<" ";
        }
        else{
            cout<<"0 ";
        }
    }


    
}