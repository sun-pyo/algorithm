#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    int size = 0;
    for(int i=1;i<=n;i++){
        size += i;        
    }
    vector<int> answer;
    answer.resize(size);
    char DRU[] = {'D', 'R', 'U'};
    int dru_idx = 0;
    int idx = 0;
    int j =1;
    int k = n;
    int h = 1;
    for(int c = 1;c<=size;c++,j++){
        answer[idx] = c;
        if(DRU[dru_idx] == 'D'){
            if(j < k){
                idx = h + idx;
                h++;
            }
            else{
                k--;
                j = 0;
                idx++;
                dru_idx++;
            }
        }
        else if(DRU[dru_idx]  == 'R'){
            if(j<k){
                idx++;
            }
            else{
                k--;
                j=0;
                idx = idx - h;
                dru_idx++;
                h--;
            }
        }
        else if(DRU[dru_idx == 'U']){
            if(j<k){
                idx = idx - h;
                h--;
            }
            else{
                k--;
                j=0;
                dru_idx=0;
                idx = h + idx;
                h++;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    arr = solution(n);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}