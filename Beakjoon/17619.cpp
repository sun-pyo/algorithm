#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Log{
    long long x1, x2, y;
    int idx;
};

bool compare(Log a, Log b){
    if(a.x1 == b.x1){
        return a.x2 > b.x2;
    }
    return a.x1 < b.x1;
}

int group[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Log> logs;
    int N, Q;
    Log temp;
    
    cin>>N>>Q;
    
    for(int i=0;i<N;i++){
        cin>>temp.x1>>temp.x2>>temp.y;
        temp.idx = i+1;
        logs.push_back(temp);
    }

    int start, end;
    vector<pair<int, int>> q;
    for(int i=0;i<Q;i++){
        cin>>start>>end;
        q.push_back(make_pair(start, end));
    }

    sort(logs.begin(), logs.end(), compare);

    long long last = logs[0].x2;
    int count = 0;
    group[logs[0].idx] = count;
    
    for(int i=1;i<N;i++){        
        if(last >= logs[i].x1){
            if(last < logs[i].x2) last = logs[i].x2;
        }
        else{
            last = logs[i].x2;
            count++;
        }
        group[logs[i].idx] = count; 
    }

    for(int i=0;i<Q;i++){
        if(group[q[i].first] == group[q[i].second])
            cout<<"1\n";
        else
            cout<<"0\n";
    }

}