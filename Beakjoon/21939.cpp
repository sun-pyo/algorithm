#include <iostream>
#include <set>
#include <map>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<pair<int, int>> ms;
    map<int, int> dict;
    int N, P, M, L, l, p, x;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>p>>l;
        ms.insert({l, p});
        dict[p] = l;
    }
    cin>>M;
    string command;
    pair<int, int> temp;
    for(int i=0;i<M;i++){
        cin>>command;
        if(command == "recommend"){
            cin>>x;
            if(x == 1){
                temp = *--ms.end();
                cout<<temp.second<<"\n";
            }
            else if(x == -1){
                temp = *ms.begin();
                cout<<temp.second<<"\n";
            }
        }
        else if(command == "add"){
            cin>>p>>l;
            ms.insert({l, p});
            dict[p] = l;
        }
        else if(command == "solved"){
            cin>>p;
            ms.erase(ms.find({dict[p], p}));
        }
    }
}