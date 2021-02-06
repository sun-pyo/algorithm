#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, num, _max = -1;
    vector<int> length;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>num;
        length.push_back(num);
        if(_max < num) _max = num;
    }

    sort(length.begin(), length.end());

    int start = 0;
    int end = _max;
    int mid, answer = 0;
    long long total;
    while(start<=end){
        mid = (start+end)/2;
        total = 0;
        for(int i=0;i<N;i++){
            if(length[i] - mid > 0)
                total += length[i] - mid;
        }

        if(total >= M){
            answer = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
    }

    cout<<answer;

}