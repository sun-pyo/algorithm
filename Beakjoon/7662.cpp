#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        multiset<int> ms;
        int k;
        char command;
        int num;
        cin>>k;
        for(int i=0;i<k;i++){
            cin>>command>>num;
            if(command == 'I'){
                ms.insert(num);
            }
            else if(!ms.empty()){
                if(num == 1){
                    ms.erase(--ms.end());
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()){
            cout<<"EMPTY\n";
        }
        else{
            int min = *ms.begin();
            int max = *--ms.end();
            cout<<max<<" "<<min<<"\n";
        }
    }
}