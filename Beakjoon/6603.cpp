#include <iostream>
#include <vector>

using namespace std;

vector<int> S;

vector<vector<int>> answer;

void solution(int idx, int count, vector<int> arr){
    if(count == 6) {
        answer.push_back(arr);
        return;
    }
    if(idx >= S.size()){
        return; 
    }
    for(int i=idx;i<S.size();i++){
        vector<int> arr1 = arr;
        arr1.push_back(S[i]);
        solution(i+1, count+1, arr1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int k;
        cin>>k;
        if(k==0) break;
        S.clear();
        S.resize(k);
        for(int i=0;i<k;i++){
            cin>>S[i];
        }
        vector<int> arr;
        answer.clear();
        solution(0, 0, arr);
        for(int i=0;i<answer.size();i++){
            for(int j=0;j<answer[i].size();j++){
                cout<<answer[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}