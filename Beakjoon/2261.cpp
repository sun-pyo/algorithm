#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 2000000000

using namespace std;

vector<pair<int, int>> points;

int dist(pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p2.first)*(p1.first - p2.first)+(p1.second - p2.second)*(p1.second - p2.second);
}

int bruteForce(int p1, int p2){
    int res = INF;
    for(int i=p1;i<p2;i++){
        for(int j=i+1;j<=p2;j++){
            res = min(res, dist(points[i], points[j]));
        }
    }
    return res;
}

int closest(int p1, int p2){
    if(p2 - p1 < 3){
        return bruteForce(p1, p2);
    }
    int mid = (p1+p2)/2;
    int distance1 = closest(p1, mid-1);
    int distance2 = closest(mid+1, p2);
    int min_distance = min(distance1, distance2);

    vector<pair<int, int>> yx;
    yx.push_back({points[mid].second, points[mid].first});
    for(int i=mid-1;i>=p1;i--){
        if(dist({points[i].first,0}, {points[mid].first, 0}) >= min_distance) break;
        yx.push_back({points[i].second, points[i].first});
    }
    for(int i=mid+1;i<=p2;i++){
        if(dist({points[i].first,0}, {points[mid].first, 0}) >= min_distance) break;
        yx.push_back({points[i].second, points[i].first});
    }
    sort(yx.begin(), yx.end());
    int distance;
    for(int i=0;i<yx.size()-1;i++){
        for(int j=i+1;j<yx.size();j++){
            if(dist({0, yx[i].first}, {0, yx[j].first}) >= min_distance) break;

            distance = dist(yx[i], yx[j]);
            min_distance = min(min_distance, distance);
        }
    }

    return min_distance;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end());
    cout<<closest(0, n-1);

}
