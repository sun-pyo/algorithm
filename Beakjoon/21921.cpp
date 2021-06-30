#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000001

int main(){
    int X, N, num;
    vector<int> arr;
    cin>>N>>X;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(num);
    }
    int max_res = 0, res = 0, cnt = 1;
    for(int i=0;i<X;i++){
        max_res += arr[i];
    }
    res = max_res;
    for(int i=X;i<N;i++){
        res = res - arr[i-X] + arr[i];
        if(res > max_res){
            max_res = res;
            cnt = 1;
        }
        else if(res == max_res) cnt++;
    }


    if(max_res == 0){
        cout<<"SAD\n";
        return 0;
    }
    else{
        cout<<max_res<<"\n";
        cout<<cnt<<"\n";
    }
}