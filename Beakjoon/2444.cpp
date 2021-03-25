#include <iostream>

using namespace std;

void draw_start(int num, int N){
    for(int i=0;i<N-num-1;i++) cout<<" ";
    for(int i=0;i<1+2*num;i++) cout<<"*";
    cout<<"\n";
}

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        draw_start(i, N);
    }
    for(int i=N-2;i>=0;i--){
        draw_start(i, N);
    }
}