#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> snack;

bool check(int mid, int M){
    int cnt = 0;
    for(int i=snack.size()-1;i>=0;i--){
        cnt += snack[i]/mid;
        if(cnt >= M) return true;
    }
    return false;
}

int main(){
    int M, N, len;
    cin>>M>>N;
    for(int i=0;i<N;i++){
        cin>>len;
        snack.push_back(len);
    }
    sort(snack.begin(), snack.end());

    int left=1, right=snack.back(), mid;
    while(left<=right){
        mid = (left + right)/2;
        if(check(mid, M)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout<<right<<"\n";
}