#include <set>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int M, num;
        multiset<int> ms;
        cin>>M;
        cout<<(M+1)/2<<"\n";
        int cnt = 0;
        for(int i=1;i<=M;i++){
            cin>>num;
            ms.insert(num);
            if(i%2 != 0){
                cnt++;
                if(cnt == 11){
                    cout<<"\n";
                    cnt = 1;
                }
                auto iter = ms.begin();
                for(int j=0;j<ms.size()/2;j++){
                    iter++;
                }
                cout<<*iter<<" ";
            }
        }
        cout<<"\n";
    }
}