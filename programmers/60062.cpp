#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> Weak;
vector<int> Dist;
int answer, N;

void sol(int idx, int count, int visit){
    if(count >= answer) return;
    for(int i=0;i<Weak.size();i++){
        int next_idx = (idx + i)%Weak.size();
        int diff = Weak[next_idx] - Weak[idx];
        if(diff < 0) diff += N;
        
        if(diff > Dist[Dist.size()-count]) break;
        visit |= (1 << next_idx);
    }
    
    if(visit == ((1<<Weak.size()) - 1)){
        answer = min(answer, count);
        return;
    }
    
    for(int i=0;i<Weak.size();i++){
        if((visit & (1<<i)) == 0) sol(i, count+1, visit);
    }
    
    
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = dist.size()+1;
    Weak = weak;
    N = n;
    sort(dist.begin(), dist.end());
    Dist = dist;
    for(int i=0;i<weak.size();i++){
        sol(i, 1, 0);
    }
    if(answer == dist.size() + 1) answer = -1;
    return answer;
}