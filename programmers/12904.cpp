#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    bool check;
    for(int size=s.size()-1;size>0;size--){
        for(int i=0;i+size<s.size();i++){
            check = true;
            for(int j=0;j<=(size+j)/2;j++){
                if(s[i+j] != s[i+size-j]){
                    check = false;
                    break;
                }
            }
            if(check) return size+1;
        }
    }
    return 1;
}