#include <iostream> 
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> set;
    int N, M, answer = 0;
    string temp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp;
        set[temp] = 1;
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        if(set.find(temp) != set.end()) answer++;
    }
    cout<<answer<<"\n";
}