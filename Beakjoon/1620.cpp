#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string temp, num;
    map<string, string> book;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>temp;
        num = to_string(i);
        book[temp] = num;
        book[num] = temp;
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        cout<<book[temp]<<"\n";
    }
}