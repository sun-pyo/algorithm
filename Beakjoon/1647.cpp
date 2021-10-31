#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int parents[100001];

typedef struct{
    int node1, node2, w;
}Data;

int find(int x){
    if(parents[x] == x) return x;
    return find(parents[x]);
}

void union_(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) parents[b] = a;
    else parents[a] = b;
}

bool compare(Data a, Data b){
    return a.w < b.w;
}

int main(){
    int N, M, w, answer=0;
    vector<Data> edge;
    Data data;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        parents[i] = i;
    }
    for(int i=0;i<M;i++){ 
        cin>>data.node1>>data.node2>>data.w;
        edge.push_back(data);
    }
    sort(edge.begin(), edge.end(), compare);
    for(Data d : edge){
        if(find(d.node1) != find(d.node2)){
            union_(d.node1, d.node2);
            answer += d.w;
            w = d.w;
        }
    }
    cout<<answer-w<<"\n";
}