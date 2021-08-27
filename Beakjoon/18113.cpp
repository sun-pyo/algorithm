#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> L;

long long get_piece(long long p){
    long long res = 0;
    for(long long l : L){
        if(l/p == 0) break;
        res += l/p;
    }
    return res;
}

void remove(int K){
    int size = L.size();
    for(int i=0;i<size;i++){
        if(L[i] < 1) {
            for(int j=i;j<size;j++) L.pop_back();
            break;
        }
    }
}

bool compare(long long a, long long b){
    return a > b;
}

int main(){
    int N, K, M;
    cin>>N>>K>>M;
    L.resize(N);
    for(int i=0;i<N;i++){
        cin>>L[i];
        if(L[i] < 2*K) L[i] -= K;
        else L[i] -= 2*K;
    }
    sort(L.begin(), L.end(), compare);
    remove(K);
    long long p, start=1, end=L[0]+1, answer=-1;
    while(start<=end){
        p = (start+end)/2;
        if(get_piece(p) < M){
            end = p-1;
        }
        else{
            answer = p;
            start = p+1;
        }
    }
    cout<<answer<<"\n";


}