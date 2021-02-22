#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DP[5000][2];
string number;

bool solution(){
    if( number[0] >= '1' && number[0] <= '9'){
        DP[0][0] = 1;
        if(number.size() >= 2){
            int num = (number[0] - '0')*10;
            num += (number[1] - '0');
            if(num >= 10 && num <= 26){
                DP[0][1]++;
                DP[1][0]++; 
            }
        }
    }
    else return false;

    for(int i=1;i<number.size();i++){
        if(number[i] >= '1' && number[i] <= '9'){
            DP[i][0] = (DP[i][0] + DP[i-1][0])%1000000;
            if(number.size() > i+1){
                int num = (number[i] - '0')*10;
                num += (number[i+1] - '0');
                if(num >= 10 && num <= 26){
                    DP[i][1] += (DP[i][1] + DP[i-1][0])%1000000;
                    DP[i+1][0] = (DP[i+1][0] + DP[i][1])%1000000; 
                }
            }
        }else if(DP[i][0] == 0){
            return false;
        }
        
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>number;
    
    if(solution())
        cout<<(DP[number.size()-1][0] + DP[number.size()-1][1])%1000000<<"\n";
    else
        cout<<0<<"\n";
}