#include <string>
#include <vector>

using namespace std;



int move_(int start, int end, int size){
    int res;
    if(start <= end){
        res = end - start;
        if(res > size - end + start) res = size - end + start;
    }
    else{
        res = start - end;
        if(res > size - start + end) res = size - start + end;
    }
    return res;
}

int change(char target){
    int res = 'Z'-target+1;
    if(res > target - 'A') res = target - 'A';
    return res;
}

int find_next(int curr, vector<int> visit){
    int idx = -1;
    int len = visit.size();
    for(int i=0;i<visit.size();i++){
        if(visit[i] == 1) continue;
        int l = move_(curr, i, visit.size());
        if(len > l){
            len = l;
            idx = i;
        }
    }
    return idx;
}

int solution(string name) {
    int answer = 0;
    int curr = 0;
    vector<int> visit;
    visit.resize(name.size());
    for(int i=0;i<name.size();i++){
        if(name[i] == 'A') visit[i] = 1;
    }
    while(true){
        int next = find_next(curr, visit);
        if(next == -1) break;
        answer += move_(curr, next, name.size());
        answer += change(name[next]);
        visit[next] = 1;
        curr = next;
    }
    return answer;
}