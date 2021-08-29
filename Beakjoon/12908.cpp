#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000001

using namespace std;

int edge[8][8] = {0,};

int getDistance(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void init_edge(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            edge[i][j] = INF;
        }
    }
}

int dijkstra(int start){
    priority_queue<pair<int ,int>> pq;
    int dist[8];
    for(int i=0;i<8;i++) dist[i] = INF;
    dist[start] = 0;
    int visit[8] = {0,};
    pq.push({0, start});
    int curr, curr_distance;
    while(!pq.empty()){
        curr_distance = -pq.top().first;
        curr = pq.top().second;
        pq.pop();
        if(dist[curr] < curr_distance) continue;
        visit[curr] = 1;
        for(int i=0;i<8;i++){
            if(visit[i] == 0 && (long long)curr_distance + edge[curr][i] < dist[i]){
                dist[i] = curr_distance + edge[curr][i];
                pq.push({-dist[i], i});
            }
        }
    }
    return dist[1];
}

int main(){
    int xs, ys, xe, ye;
    vector<pair<int, int>> points(8);
    init_edge();
    cin>>xs>>ys>>xe>>ye;
    points[0] = {xs, ys};
    points[1] = {xe, ye};
    int x1, y1, x2, y2;

    for(int i=2;i<8;i+=2){
        cin>>x1>>y1>>x2>>y2;
        points[i] = {x1, y1};
        points[i+1] = {x2, y2};
        edge[i][i+1] = 10;
        edge[i+1][i] = 10;
    }

    for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            x1 = points[i].first;
            y1 = points[i].second;
            x2 = points[j].first;
            y2 = points[j].second;
            edge[i][j] = min(edge[i][j], getDistance(x1, y1, x2, y2));
        }
    }
    cout<<dijkstra(0);

}