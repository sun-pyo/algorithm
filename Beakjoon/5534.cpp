#include <vector>
#include <iostream>
#include <string>

using namespace std;

int find_string(string s, string target){
    string temp;
    for(int blank=0;blank<s.size();blank++){
        for(int start=0;start<s.size();start++){
            temp = "";
            for(int i=start;i<s.size();i+=(blank+1)){
                temp += s[i];
            }

            if(temp.find(target) != string::npos) return 1;
        }
    }
    return 0;
}

int main(){

    int N, answer = 0;
    string market_name, old_name;
    cin>>N;
    cin>>market_name;
    
    for(int i=0;i<N;i++){
        cin>>old_name;
        answer += find_string(old_name, market_name);
    }
    cout<<answer;

}