#include <vector>
#include <iostream>
#include <string>

#define INF 2000000000

using namespace std;

int max_answer, min_answer;

void solution(string N, int cnt){
    for(int i=0;i<N.size();i++){
        if((N[i]-'0')%2 == 1) cnt++;
    }
    if(N.size() == 1) {
        max_answer = max(max_answer, cnt);
        min_answer = min(min_answer, cnt);
        return;
    }
    if(N.size() == 2) {
        long long num = (N[0] - '0') + (N[1] - '0');
        solution(to_string(num), cnt);
    }
    else if(N.size() >= 3){
        for(int a=1;a<=N.size()-2;a++){
            for(int b=1;a+b<=N.size()-1;b++){
                long long num = stol(N.substr(0, a)) + stol(N.substr(a, b)) + stol(N.substr(a+b));
                solution(to_string(num), cnt);
            }
        }
    }
}

int main(){
    string N;
    cin>>N;
    max_answer=-INF;
    min_answer=INF;
    solution(N, 0);
    cout<<min_answer<<" "<<max_answer<<"\n";
}
