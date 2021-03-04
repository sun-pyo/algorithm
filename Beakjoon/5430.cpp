#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        string cmd;
        cin>>cmd;
        int N;
        cin>>N;
        string arr_str;
        vector<int> arr;
        cin>>arr_str;
        int num = 0;
        if(N != 0){
            for(int i=1;i<arr_str.size();i++){
                if(arr_str[i] >= '0' && arr_str[i] <= '9'){
                    num *= 10;
                    num += arr_str[i] - '0';
                }
                else if(arr_str[i] == ',' || arr_str[i] == ']'){
                    arr.push_back(num);
                    num = 0;
                }
            }
        }
        int reverse = -1;
        int start = 0; 
        int end = N;
        bool err = false;

        for(int i=0;i<cmd.size();i++){
            if(cmd[i] == 'R')
                reverse *= -1;
            else if(cmd[i] == 'D'){
                if(reverse == -1){
                    start++;
                }
                else{
                    end--;
                }

                if(start > end) err = true;
            }
        }
        if(err){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            if(reverse == -1){
                for(int i=start;i<end;i++){
                    if(i != end-1)
                        cout<<arr[i]<<",";
                    else
                        cout<<arr[i];
                }
            }
            else{
                for(int i=end-1;i>=start;i--){
                    if(i != start)
                        cout<<arr[i]<<",";
                    else
                        cout<<arr[i];
                }
            }
            cout<<"]\n";
        }
    }
}