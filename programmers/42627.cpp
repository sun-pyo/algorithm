#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Data{
    int reqTime, durationTime;
    
    bool operator()(Data a, Data b){
        if(a.durationTime == b.durationTime){
            return a.reqTime < b.reqTime;
        }
        else return a.durationTime > b.durationTime;
    }
}Data;

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, curr=0, cnt = 0;
    priority_queue<Data, vector<Data>, Data> pq; 
    sort(jobs.begin(), jobs.end(), compare);
    Data data;
    while(cnt < jobs.size()){
        while(idx<jobs.size()&&jobs[idx][0] <= curr){
            data.reqTime = jobs[idx][0];
            data.durationTime = jobs[idx][1];
            pq.push(data);
            idx++;
        }
        if(!pq.empty()){
            data = pq.top();
            answer += curr - data.reqTime + data.durationTime;
            curr += data.durationTime - 1;
            pq.pop();
            cnt++;
        }
        curr++;
    }
    answer /= jobs.size();
    return answer;
}