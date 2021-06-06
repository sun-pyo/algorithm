#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, H, W, idx;
    string answer = "";
    vector<string> input;
    cin>>N>>H>>W;
    for(int i=0;i<N;i++){
        answer += "?";
    }
    input.resize(H);
    for(int i=0;i<H;i++){
        cin>>input[i];
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<N*W;j++){
            idx = j/W;
            if(answer[idx] == '?' && input[i][j] != '?'){
                answer[idx] = input[i][j];
            }
        }
    }
    cout<<answer;
    
}