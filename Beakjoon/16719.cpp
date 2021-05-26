#include <vector>
#include <string>
#include <iostream>

using namespace std;

string str;
bool visit[100];

void sol(int start, int end){
    char min_ = 'Z' + 1;
    int mid = -1;
    for(int i=start;i<=end;i++){
        if(!visit[i] && str[i] < min_){
            min_ = str[i];
            mid = i;
        }
    }
    if(mid == -1) return;
    visit[mid] = true;
    for(int i=0;i<str.size();i++){
        if(visit[i]) cout<<str[i];
    }
    cout<<"\n";
    sol(mid+1, end);
    sol(start, mid-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str;
    sol(0, str.size()-1);

}