#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> points;
    int N, color, point, answer = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>point>>color;
        points.push_back({point, color});
    }
    sort(points.begin(), points.end());
    int dist;
    for(int i=0;i<points.size();i++){
        dist = 100000;
        for(int j=i+1;j<points.size();j++){
            if(points[i].second == points[j].second){
                dist = points[j].first - points[i].first;
                break;
            }
        }
        for(int j=i-1;j>=0;j--){
            if(points[i].second == points[j].second){
                dist = min(dist, points[i].first - points[j].first);
                break;
            }
        }
        answer += dist;
    }
    cout<<answer<<"\n";
}