#include <string>
#include <iostream>

using namespace std;

int main(){
    string s, t;
    while(cin>>s>>t){
        int j = 0, cnt = 0;
        for(int i=0;i<s.size();i++){
            while(j < t.size()){
                if(s[i] == t[j++]){
                    cnt++;
                    break;
                }
            }
        }
        if(s.size() == cnt) cout<<"Yes\n";
        else cout<<"No\n";
    }
}