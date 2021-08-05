#include <iostream>
#include <vector>
#include <queue>

#define INF 10000001

using namespace std;

vector<vector<pair<int, int>>> edge;

void dijkstra(int start, int n){
    // distance, first node
    vector<pair<int, int>> dist;
    dist.resize(n);
    for(int i=0;i<n;i++){
        if(i == start) dist[i] = {0, i};
        else dist[i] = {INF, i};
    }
    // distance, next node
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    int curr, next, distance, w;
    while (!pq.empty())
    {
        w = -pq.top().first;
        curr = pq.top().second;
        pq.pop();
        if(dist[curr].first < w) continue;

        for(int i=0;i<edge[curr].size();i++){
            next = edge[curr][i].second;
            distance = edge[curr][i].first;
            if(dist[next].first > w + distance){
                //cout<<"next = "<<next<<"\n";
                dist[next].first = w + distance;
                if(curr != start) dist[next].second = dist[curr].second;
                pq.push({-dist[next].first, next});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i == start) cout<<"- ";
        else cout<<dist[i].second+1<<" ";
    }
    cout<<"\n";
}

int main(){
    int n, m, node1, node2, distance;
    cin>>n>>m;
    edge.resize(n);
    for(int i=0;i<m;i++){
        cin>>node1>>node2>>distance;
        node1--;
        node2--;
        edge[node1].push_back({distance, node2});
        edge[node2].push_back({distance, node1});
    }
    for(int i=0;i<n;i++){
        dijkstra(i, n);
    }

}