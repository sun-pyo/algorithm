#include <iostream>
#include <vector>

#define INF 15000

using namespace std;

int dist[100][100];

void init_graph(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

int main(){
    int n, m, r, num, node1, node2, distance;
    vector<int> item;
    cin>>n>>m>>r;
    init_graph(n);
    for(int i=0;i<n;i++){
        cin>>num;
        item.push_back(num);
    }
    for(int i=0;i<r;i++){
        cin>>node1>>node2>>distance;
        node1--;
        node2--;
        dist[node1][node2] = distance;
        dist[node2][node1] = distance;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    int answer = 0, item_cnt;
    for(int i=0;i<n;i++){
        item_cnt = 0;
        for(int j=0;j<n;j++){
            if(dist[i][j] <= m){
                item_cnt += item[j];
            }
        }
        if(answer < item_cnt) answer = item_cnt;
    }
    cout<<answer;
}