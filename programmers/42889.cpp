#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b)
{
    if(a.first == b.first){
        return a.second<b.second;
    }
    else 
        return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt;
    cnt.resize(N);
    int total_cnt = 0;
    for(int i=0;i<stages.size();i++){
        if(stages[i] >= N+1) total_cnt++;
        else cnt[stages[i]-1]++;
    }
    vector<pair<double, int>> fail;
    for(int i=N-1;i>=0;i--){
        if(cnt[i] + total_cnt == 0){
            fail.push_back(make_pair(0, i));
        }
        else{
            double fail_rate = (double)cnt[i]/(total_cnt+cnt[i]);
            fail.push_back(make_pair(fail_rate, i));    
            total_cnt += cnt[i];
        }
    }
    sort(fail.begin(), fail.end(), compare);
    for(int i=0;i<fail.size();i++){
        answer.push_back(fail[i].second+1);
    }
    return answer;
}