#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    string s;
    for(int t=0;t<T;t++){
        cin>>s;
        int cnt, f, b, cnt_f = 0, cnt_b = 0;
        cnt = 0;
        f = 0;
        b = s.size()-1;
        for(int i=0;i<s.size()/2;i++){
            if(s[f+i] != s[b-i]){
                cnt++;
                break;
            }
        }
        if(cnt == 0){
            cout<<"0\n";
            continue;
        } 
        for(int i=0;i<=s.size()/2;i++){
            if(s[f+i] != s[b-i]){
                f++;
                cnt_f++;
                if(cnt_f >= 2) break;
            }
        }
        f = 0;
        for(int i=0;i<=s.size()/2;i++){
            if(s[f+i] != s[b-i]){
                b--;
                cnt_b++;
                if(cnt_b >= 2) break;
            }
        }
        if(cnt_b > cnt_f) cnt = cnt_f;
        else cnt = cnt_b;
        cout<<cnt<<"\n";
    }
}