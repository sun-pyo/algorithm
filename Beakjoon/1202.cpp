#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second; 
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> jewelry; // 무게, 가격
    vector<int> bag;
    
    int N,K, m, v, c;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>m>>v;
        jewelry.push_back(make_pair(m, v));
    }
    for(int i=0;i<K;i++){
        cin>>c;
        bag.push_back(c);
    }

    sort(jewelry.begin(), jewelry.end(), compare);
    sort(bag.begin(), bag.end());
    
    long long answer = 0;
    int count = 0, j=0;
    priority_queue<int> pq;
    for(int i=0; i<K ;i++){
        while(j<N && bag[i] >= jewelry[j].first) 
        {   
            pq.push(jewelry[j].second);
            j++;
        }
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    cout<<answer;

}