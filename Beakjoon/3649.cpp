#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {return a>b;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        int x, n, num;
        cin>>x>>n;
        if(cin.eof() == true) break; 
        x *= 10000000;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin>>num;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end(), compare);

        int l1, l2;
        bool answer = false;

        for(int i=0;!answer && i<n;i++){
            if(arr[i] < x/2) break;
            int start = i + 1;
            int end = n - 1;
            int mid;
            int key = x - arr[i];
            while(start <= end){
                mid = (start + end)/2;
                if(mid != i && key == arr[mid]){
                    answer = true;
                    l1 = key;
                    l2 = arr[i];
                    break;
                }

                if(key > arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }

        if(answer){
            cout<<"yes "<<l1<<" "<<l2<<"\n";
        }
        else{
            cout<<"danger\n";
        }

        arr.clear();
    }
}