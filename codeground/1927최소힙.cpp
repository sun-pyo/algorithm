#include<stdio.h>
#include<iostream>

using namespace std;

long long heap[100001];
long long heap_size = 0;

long long pop_heap(){
    if(heap_size > 0){
        long long min_data = heap[1];
        long long temp = heap[heap_size];
        long long child = 2, parent = 1;
        heap_size--;
        
        while(child <= heap_size){
            if(child < heap_size && heap[child] > heap[child+1])
                child++;
            
            if(temp <= heap[child]){
                break;
            }

            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        
        }
        heap[parent] = temp;
        return min_data;
    }
    return 0;
}

void push_heap(long long data){
    int i = ++heap_size;
    while(i!=1 && data < heap[i/2]){
        heap[i] = heap[i/2];
        i/=2;
    }
    heap[i] = data;
    return;
}

int main(){
    int N;
    long long x, d = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        if(x>0)
            push_heap(x);
        else if(x==0)
        {
            printf("%d \n",pop_heap());
        }
    }
}