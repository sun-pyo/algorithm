#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_second(vector<int> temp_arr){
    sort(temp_arr.begin(), temp_arr.end());
    return temp_arr[2];
}

vector<vector<int>> pooling(vector<vector<int>> arr){
    vector<vector<int>> result;
    int num;
    for(int i=0;i<arr.size();i+=2){
        vector<int> temp;
        for(int j=0;j<arr.size();j+=2){
            num = find_second({arr[i][j], arr[i+1][j], arr[i][j+1], arr[i+1][j+1]});
            temp.push_back(num);
        }
        result.push_back(temp);
    }   
    return result;
}

int main(){
    int N;
    cin>>N;
    vector<vector<int>> arr(N);
    for(int i=0;i<N;i++){
        arr[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    while(arr.size()!=1){
        arr = pooling(arr);
    }
    cout<<arr[0][0];
}