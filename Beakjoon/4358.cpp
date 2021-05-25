#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    map<string, float> count_str;
    float total_num = 0;
    while(getline(cin,str)){
        if(count_str.find(str) == count_str.end()){
            count_str[str] = 1;
        }
        else count_str[str]++;
        total_num++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto& temp : count_str){
        cout<<temp.first<<" "<<(temp.second*100)/total_num<<"\n";
    }
}