#include <iostream>
#include <vector>

using namespace std;

typedef struct Data{
    int num;
    int next;
    int pre;
}data;

int main(){
    vector<Data> d;
    vector<int> answer;
    int N, K;
    cin>>N>>K;
    Data temp;
    for(int i=1;i<=N;i++){
        temp.num = i;
        temp.next = i%N;
        if(i == 1)
            temp.pre = N-1;
        else
            temp.pre = i-2;
        d.push_back(temp);
    }
    int curr = 0, pre = 0, next;
    int k = K, n = N;
    while(n!=0){
        if(k == 1){
            k = K;
            answer.push_back(d[curr].num);
            next = d[curr].next;
            pre = d[curr].pre;
            d[pre].next = next;
            d[next].pre = pre;
            d[curr].next = -1;
            curr = next;
            n--;
            continue;
        }
        k--;
        curr = d[curr].next;
    }
    cout<<"<";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
        if(i!=answer.size()-1)
            cout<<", ";
    }   
    cout<<">";
}