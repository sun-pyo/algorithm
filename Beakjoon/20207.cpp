#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int calendar[366] = {0,};

int main(){
    vector<pair<int, int>> arr;
    int N, start, end, max_h;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>start>>end;
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end(), compare);


    for(int i=0;i<arr.size();i++){
        start = arr[i].first;
        end = arr[i].second;
        for(int j=start;j<=end;j++){
            calendar[j]++;
        }
    }
    int answer = 0, len = 0;
    max_h = 0;
    for(int i=1;i<=365;i++){
        if(calendar[i] > 0){
            if(max_h < calendar[i]) max_h = calendar[i];
            len++;
        }else{
            answer += len*max_h;
            len = 0;
            max_h = 0;
        }
    }
    answer += len*max_h;
    cout<<answer;
}