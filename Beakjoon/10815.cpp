#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,num;
    vector<int> arr;
    vector<int> q;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }

    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num;
        q.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    vector<int> answer;

    for(int i=0;i<M;i++){
        int start = 0;
        int end = N-1;
        int mid;
        bool exist = false;
        while(start <= end){
            mid = (start+end)/2;

            if(arr[mid] == q[i]){
                exist = true;
                break;
            }

            if(arr[mid] < q[i]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        if(exist){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
        cout<<answer.back()<<" ";
    }

    

}