#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parents;

typedef struct Data{
    int node1, node2, w;
}Data;

bool compare(Data a, Data b){
    return a.w < b.w;
}

int find(int x){
    if(parents[x] == x) return x;
    return find(parents[x]);
}

void _union(int a, int b){
    int a_par, b_par;
    a_par = find(a);
    b_par = find(b);
    if(a_par <= b_par) parents[b_par] = a_par;
    else parents[a_par] = b_par;
}

int main(){
    int N, M, answer=0;
    cin>>N;
    cin>>M;
    vector<Data> edge;
    parents.resize(N);
    for(int i=0;i<M;i++){
        Data data;
        cin>>data.node1>>data.node2>>data.w;
        data.node1-=1;
        data.node2-=1;
        edge.push_back(data);
    }
    for(int i=0;i<N;i++){
        parents[i] = i;
    }
    sort(edge.begin(), edge.end(), compare);
    for(Data data : edge){
        int node1, node2;
        node1 = data.node1;
        node2 = data.node2;
        if(find(node1) != find(node2)){
            answer += data.w;
            _union(node1, node2);
        }
    }
    cout<<answer<<"\n";
}
