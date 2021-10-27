#include <vector>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

void move_card(queue<int> &q1, queue<int> &q2, queue<int> &res, int k, int i){
    for(int j=0;j<pow(2, k-i+1);j++){
        q2.push(q1.front());
        q1.pop();
    }
    while(!q1.empty()){
        res.push(q1.front());
        q1.pop();
    }
}

queue<int> simulation(queue<int> q1, int k){
    queue<int> q2;
    queue<int> res;
    for(int i=1;i<=k+1;i++){
        if(i%2 != 0){
            move_card(q1, q2, res, k, i);
        }
        else{
            move_card(q2, q1, res, k, i);
        }
    }
    while(!q1.empty()){
        res.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        res.push(q2.front());
        q2.pop();
    }
    return res;
}

int main(){
    queue<int> card_q, temp;
    vector<int> target;
    int N, k1, k2;
    bool check;
    cin>>N;
    target.resize(N);
    for(int i=0;i<N;i++){
        cin>>target[i];
        card_q.push(N-i);
    }
    for(int i=1;pow(2, i)<N;i++){
        for(int j=1;pow(2, j)<N;j++){
            temp = simulation(card_q, i);
            temp = simulation(temp, j);
            check = true;
            for(int t=1;t<=N;t++){
                if(temp.front() != target[N-t]){
                    check = false;
                    break;
                }
                temp.pop();
            }
            if(check){
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }

}