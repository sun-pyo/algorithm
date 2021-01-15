#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool compare(pair<long long,long long> a, pair<long long, long long> b){
    return a.second < b.second;
}

int main(){
    int N;
    scanf("%d",&N);
    
    vector<pair<long long,long long>> meeting;
    long long start, end;
    for(int i = 0;i<N;i++){
        scanf("%lld %lld", &start, &end);
        meeting.push_back(make_pair(start, end));
    }

    sort(meeting.begin(), meeting.end(), compare);
    
    int answer = 0;
    long long last = -1;
    
    for(int i = 0;i<meeting.size();i++){
        if( last <= meeting[i].first){
            last = meeting[i].second;
            answer++;
        }    
    }
    printf("%d", answer);
}