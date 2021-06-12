#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int abs(int num){
    if(num < 0) return -num;
    else return num;
}

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b) ){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, compare> pq;
    int N, num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        if(num == 0){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            } 
        }
        else{
            pq.push(num);
        }
    }
}