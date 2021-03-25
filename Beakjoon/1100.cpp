#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> chess;
    chess.resize(8);
    for(int i=0;i<8;i++){
        cin>>chess[i];
    }

    int k, answer = 0;
    for(int r=0;r<8;r++){
        if(r%2==0) k = 0;
        else k = 1;
        for(int c=k;c<8;c+=2){
            if(chess[r][c] == 'F') answer++;
        }
    }
    cout<<answer;
}