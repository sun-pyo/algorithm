#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin>>T;
    for(int t=0;t<T;t++){
        int cnt = 0;
        int N, M;
        cin>>N>>M;
        for(int i=N;i<=M;i++){
            string string_num = to_string(i);
            for(int j=0;j<string_num.size();j++){
                if(string_num[j] == '0') cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}