#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    deque<int> dq;
    vector<int> command;
    vector<int> answer;
    int N, front, idx;
    cin>>N;
    command.resize(N);
    answer.resize(N);
    for(int i=0;i<N;i++){
        cin>>command[i];
        dq.push_back(i);
    }
    for(int i=N;i>=1;i--){
        if( command[N-i] == 1){
            idx = dq.front();
            dq.pop_front();
        }
        else if(command[N-i] == 2){
            front = dq.front();
            dq.pop_front();
            idx = dq.front();
            dq.pop_front();
            dq.push_front(front);
        }
        else if(command[N-i] == 3){
            idx = dq.back();
            dq.pop_back();
        }
        answer[idx] = i;
    }
    for(int i=0;i<N;i++){
        cout<<answer[i]<<" ";
    }
}