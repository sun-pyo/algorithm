#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int T=0;T<t;T++){
        int n;
        vector<string> call_list;
        string temp, check_str;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            call_list.push_back(temp);
        }   
        sort(call_list.begin(), call_list.end());
        bool YES = true;
        for(int i=0;i<n-1;i++){
            temp = call_list[i];
            for(int j=i+1;j<n;j++){
                check_str = call_list[j].substr(0, temp.size());
                if(temp == check_str){
                    YES = false;
                    break;
                }
                else if(temp < check_str) break;
            }
            if(!YES) break;
        }
        if(YES) cout<<"YES\n";
        else cout<<"NO\n";
    }
}