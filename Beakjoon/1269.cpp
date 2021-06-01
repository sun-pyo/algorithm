#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int, int> cnt;
    int A,B, num, answer = 0;
    cin>>A>>B;
    for(int i=0;i<A+B;i++){
        cin>>num;
        if(cnt.find(num) == cnt.end()) cnt[num] = 0;
        else cnt[num] = 1; 
    }
    for(auto &temp : cnt){
        if(temp.second == 0) answer++;
    }
    cout<<answer;
}