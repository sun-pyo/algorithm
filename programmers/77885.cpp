#include <string>
#include <vector>

using namespace std;

string to_byte(long long num){
    string b = "";
    string temp;
    while(num){
        temp = to_string(num%2);
        b = temp + b;
        num /= 2;
    }
    b = "0" + b;
    return b;
}

string f(string x){
    for(int i=x.size()-1;i>=0;i--){
        if(x[i] == '0'){
            x[i] = '1';
            if(i+1 < x.size() && x[i+1] == '1') x[i+1] = '0';
            break;
        }
    }
    return x;
}

long long to_ten(string byte){
    long long res = 0, num, mul=1;
    for(int i=byte.size()-1;i>=0;i--){
        num = byte[i] - '0';
        res += mul*num;
        mul *= 2;
    }
    return res;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    string x, fx;
    for(int i=0;i<numbers.size();i++){
        x = to_byte(numbers[i]);
        fx = f(x);
        answer.push_back(to_ten(fx));
    }
    return answer;
}