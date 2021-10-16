#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    int N, id, start, end;
    vector<pair<int, int>> start_end;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>id>>start>>end;
        start_end.push_back({start, end});
    }
    sort(start_end.begin(), start_end.end(), compare);

    priority_queue<int> end_pq;
    int cnt=0, answer=0;
    for(int i=0;i<start_end.size();i++){
        start = start_end[i].first;
        end = start_end[i].second;

        while(!end_pq.empty() && start >= -end_pq.top()){
            cnt--;
            end_pq.pop();
        }
        end_pq.push(-end);
        cnt += 1;
        answer = max(answer, cnt);
    }
    cout<<answer<<"\n";
}