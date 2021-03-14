#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b){
    int i=0, j=0;
    while(true){
        if(a[i] == b[j]){
            i++;
            j++;
            if(i == a.size() && j ==b.size()){
                return a > b;
            }
            else if(i == a.size()){
                i = 0;
            }else if(j == b.size()){
                j = 0;    
            }
        }
        else
            return a[i]>b[j];
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> arr;
    for(int i=0;i<numbers.size();i++){
        arr.push_back(to_string(numbers[i]));
    }
    sort(arr.begin(), arr.end(),compare);
    if(arr[0] == "0"){
        answer = "0";
    }
    else{
        for(int i=0;i<arr.size();i++){
        answer += arr[i];
        }    
    }
    
    return answer;
}
int main(){
    cout<<solution({1,2,21, 21});
}