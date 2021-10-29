#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

vector<queue<int>> all;
queue<int> temp_q;
vector<int> temp;
int visit[21] = {0,};
string s;

void get_all(int idx){
    if(idx == s.size()){
        for(int i=0;i<temp.size();i++){
            temp_q.push(temp[i]);
        }
        all.push_back(temp_q);
        while(!temp_q.empty()) temp_q.pop();
        return;
    }
    if(idx == 0 || (idx-1>=0 && visit[idx-1] == 0)){
        temp.push_back(idx);
        visit[idx] = 1;
        get_all(idx+1);
        visit[idx] = 0;
        temp.pop_back();
    }

    get_all(idx+1);
}

int calculate(int a, int b, char cal){
    if(cal == '-') return a-b;
    else if(cal == '+') return a+b;
    else if(cal == '*') return a*b;
}

int main(){
    int N, num, idx, answer = INT_MIN;
    queue<int> num_q;
    cin>>N;
    cin>>s;
    get_all(0);
    for(int i=0;i<all.size();i++){
        memset(visit, 0, sizeof(visit));
        for(int j=0;j*2+1<N;j++){
            if(!all[i].empty()&& all[i].front() == j){
                idx = 2*j + 1;
                num = calculate(s[idx-1]-'0', s[idx+1] - '0', s[idx]);
                num_q.push(num);
                visit[idx] = 1;
                visit[idx-1] = 1;
                visit[idx+1] = 1;
                all[i].pop();
                continue;
            }
            if(visit[2*j] == 0){
                num_q.push(s[2*j] - '0');
                visit[2*j] = 1;
            }
        }
        if(visit[N-1] == 0) num_q.push(s[N-1] - '0');
        num = num_q.front();
        num_q.pop();
        for(int j=0;j*2+1<N;j++){
            idx = j*2+1;
            if(visit[idx] == 1) continue;
            num = calculate(num, num_q.front(), s[idx]);   
            num_q.pop();
        }
        answer = max(answer, num);
    }
    cout<<answer<<"\n";
}