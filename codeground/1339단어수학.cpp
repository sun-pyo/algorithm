#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int value[26];

void cal(string s){
    int k = 1;
    for(int i=s.size()-1;i>=0;i--){
        value[s[i]-'A'] += k;
        k*=10;
    }
}

bool compare(int a, int b){
    return a > b;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(value, 0, sizeof(value));

    int N;
    string str[10];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str[i];  
        cal(str[i]);
    }

    int big = 9;
    unsigned long long result = 0;
    
    sort(value, value+26,compare);

    for(int i=0;i<10;i++){
        if(value[i] != -1){
            result += (value[i] * big);
            big--;
        }    
    }
    cout<<result;   
}