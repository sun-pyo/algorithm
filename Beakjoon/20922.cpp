#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int N, K, num;
    cin>>N>>K;
    vector<int> arr;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }
    map<int, int> dict;
    int left=0, right=0, len=0, max_len=0;
    while(right < arr.size()){
        if(dict[arr[right]] == K){
            while(dict[arr[right]] >= K){
                --dict[arr[left++]];
                len--;
            }
        }
        ++dict[arr[right++]];
        len++; 
        if(max_len < len) max_len = len;
    }
    cout<<max_len<<"\n";
}