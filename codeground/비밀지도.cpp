#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int val;
    for(int i = 0;i<arr1.size();i++){
        val = arr1[i]|arr2[i];
        vector<int> s;
        while(val){
            s.push_back(val%2);
            val/=2;
        }
        string str;
        for(int k=0;k<arr1.size();k++){
            if(s.back() == 1)
                str.append("#");
            else 
                str.append(" ");
            s.pop_back();
        }
        answer.push_back(str);
    }

    return answer;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0;i<prices.size();i++){
        int count = 0;
        for(int j=i;j<prices.size()-1;j++){
            if(prices[i] > prices[j]) break;
            count++;
        }
        answer.push_back(count);
        cout<<count<<" ";
    }
    return answer;
}

int main(){
    vector<int> arr = {1,2,3,2,3};
    solution(arr);
}