#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int next;
    int pre;
    int move;
}node;

int main(){
    vector<node> list;
    node temp;
    int N, move;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>move;
        if(i != N-1) temp.next = i+1;
        else temp.next = 0;
        if(i != 0) temp.pre = i-1;
        else temp.pre = N-1;
        temp.move = move;
        list.push_back(temp);
    }

    int curr = 0;
    int next, pre;
    for(int i=0;i<N;i++){
        next = list[curr].next;
        pre = list[curr].pre;

        list[next].pre = pre;
        list[pre].next = next;

        cout<<curr+1<<" ";

        move = list[curr].move;
        
        if(move < 0){
            move = -move;
            for(int k=0;k<move;k++){
                curr = list[curr].pre;
            }
        }
        else{
            for(int k=0;k<move;k++){
                curr = list[curr].next;
            }
        }
    }

}