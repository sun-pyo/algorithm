#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> Dungeons;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

int visit[5000] = {0,};

int sol(int idx, int k, int count){
    visit[idx] = 1;
    k -= Dungeons[idx][1];
    int res = count;
    for(int i=0;i<Dungeons.size();i++){
        if(visit[i] == 0 && Dungeons[i][0] <= k){
            res = max(res, sol(i, k, count+1));
        }
    }
    visit[idx] = 0;

    return res;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    Dungeons = dungeons;
    for(int i=0;i<dungeons.size();i++){
        answer = max(answer, sol(i, k, 1));    
    }
    return answer;
}