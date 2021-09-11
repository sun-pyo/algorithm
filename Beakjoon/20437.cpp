#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define INF 2000000000

using namespace std;

int main(){
    int T, K, first_answer, second_answer;
    string W;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>W>>K;
        first_answer = INF;
        second_answer = -INF;
        for(int i=0;i<26;i++){
            char ch = 'a' + i;
            vector<int> pos;
            for(int j=0;j<W.size();j++){
                if(W[j] == ch) pos.push_back(j);
            }
            if(pos.size() < K) continue;
            for(int j=0;j+K-1<pos.size();j++){
                first_answer = min(first_answer, pos[j+K-1] - pos[j] + 1); 
                second_answer = max(second_answer, pos[j+K-1] - pos[j] + 1);
            }
        }
        if(first_answer == INF) cout<<"-1\n";
        else cout<<first_answer<<" "<<second_answer<<"\n";
    }
}