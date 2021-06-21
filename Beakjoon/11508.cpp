#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int N;
    vector<int> C;
    cin>>N;
    C.resize(N);
    for(int i=0;i<N;i++){
        cin>>C[i];
    }
    sort(C.begin(), C.end(), compare);
    int answer=0;
    for(int i=0;i<N;i++){
        if((i+1)%3 == 0) continue;
        answer += C[i];
    }
    cout<<answer;
}