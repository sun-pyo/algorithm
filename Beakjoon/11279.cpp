#include <vector>
#include <iostream>

using namespace std;

class Heap{
    vector<int> heap;
    int size;
    public:
    Heap(){
        heap.push_back(0);
        size = 0;
    }
    void push(int num){
        heap.push_back(num);
        size++;
        if(size == 1){
            return;
        }
        int child = size;
        int parents = child/2;
        while(parents > 0 && heap[parents] < num){
            heap[child] = heap[parents];
            child = parents;
            parents = child/2;
        }
        heap[child] = num;
    }

    int pop(){
        if(size == 0){
            return 0;
        }
        int top = heap[1];
        int num = heap.back();
        heap.pop_back();
        size--;
        if(size < 1) return top;
        int child = 2;
        int parents = 1;
        while(child <= size){
            if(size >= child + 1 && heap[child + 1] > heap[child]){
                child++;
            }
            if(num > heap[child]) break;
            heap[parents] = heap[child];
            
            parents = child;
            child *= 2;
        }
        heap[parents] = num;
        return top;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Heap heap;
    int N, num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        if(num == 0) cout<<heap.pop()<<"\n";
        else heap.push(num);
    }

}