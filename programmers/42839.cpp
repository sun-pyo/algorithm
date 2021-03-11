#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

bool is_prime(int num){
    if(num <= 1) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> arr;
    int number[] = {9, 99, 999, 9999, 99999, 999999, 9999999};
    int end = number[numbers.size()-1];
    for(int i=2;i<=end;i++){
        if(is_prime(i)){
            arr.push_back(i);
        }
    }
    
    vector<int> in_numbers;
    in_numbers.resize(10);
    for(int i=0;i<numbers.size();i++){
        in_numbers[numbers[i] - '0']++;
    }
    bool check;
    for(int i=0;i<arr.size();i++){
        int num = arr[i];
        check = true;
        vector<int> temp = in_numbers;
        int k = num;
        while(k){
            int n = k%10;
            k/=10;
            if(temp[n] == 0){
                check = false;
                break;
            }
            temp[n]--;
        }
        if(check){
            answer++;
        }
    }
    
    return answer;
}

int main(){
    std::cout<<solution("011");

}