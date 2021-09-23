#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> answer;
string N;

void solution(int l, int r, int count, string num){
    if(count == N.size()){
        answer.insert(num);
        return;
    }
    if(l > 0){
        solution(l-1, r, count+1, num + "-" + N.substr(l-1, count+1));
    }
    if(r+1 < N.size()){
        solution(l, r+1, count+1, num + "-" + N.substr(l, count+1));
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N.size();i++){
        solution(i, i, 1, N.substr(i,1));
    }
    cout<<answer.size()<<"\n";
}