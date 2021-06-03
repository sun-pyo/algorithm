#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string S, T;

int sol(string t){
    if(t.size() < S.size()) return 0;
    else if(t == S) return 1;
    int res = 0;

    if(t.back() == 'A'){
        res += sol(t.substr(0, t.size()-1));
    }
    if(t[0] == 'B') {
        reverse(t.begin(), t.end());
        t.pop_back();
        res += sol(t);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>S>>T;
    int res = sol(T);
    if(res >= 1) cout<<1<<"\n";
    else cout<<0<<"\n";

}