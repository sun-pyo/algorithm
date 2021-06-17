#include <iostream>
#include <string>


using namespace std;

int main(){
    string input;
    cin>>input;
    int cnt_X = 0;
    for(int i=0;i<input.size();i++){
        if(input[i] == 'X'){
            cnt_X++;
            if(cnt_X == 4){
                while(cnt_X){
                    input[i-cnt_X+1] = 'A';
                    cnt_X--;
                }
            }
            else if(i == input.size()-1){
                if(cnt_X%2 != 0){
                cout<<"-1\n";
                return 0;
                }
                else{
                    while(cnt_X){
                        input[i-cnt_X+1] = 'B';
                        cnt_X--;
                    }
                }
            }
        }
        else if(input[i] == '.'){
            if(cnt_X%2 != 0){
                cout<<"-1\n";
                return 0;
            }
            else{
                while(cnt_X){
                    input[i-cnt_X] = 'B';
                    cnt_X--;
                }
            }
        }
    }
    cout<<input;
}