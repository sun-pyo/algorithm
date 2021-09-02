#include <vector>
#include <iostream>
#include <string>

using namespace std;

int prime[1003001] = {0,};

bool check(string s){
    int size = s.size();
    for(int i=0;i<=size/2;i++){
        if(s[i] != s[size-1-i]) return false;
    }
    return true;
}

int main(){
    int N, answer = 1;
    cin>>N;
    for(int i=2;i<=1003001;i++){
        if(prime[i] == 0){
            if(i >= N && check(to_string(i))){
                answer = i;
                break;
            }
            for(int j=i+i;j<=1003001;j+=i){
                prime[j] = -1;
            }
        }
    }
    cout<<answer;
}