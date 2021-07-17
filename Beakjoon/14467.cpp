#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N, num1, num2, answer = 0;  
    cin>>N;

    vector<vector<int>> hist;
    hist.resize(10); 
    for(int i=0;i<N;i++){
        cin>>num1>>num2;

        if(!hist[num1-1].empty() && hist[num1-1].back() != num2){
            answer++;
        }
        hist[num1-1].push_back(num2);
    }
    cout<<answer;
}