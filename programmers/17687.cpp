#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, string> dict;

string to_n(int number, int n){
    string res = "";
    int num;
    do{
        num = number%n;
        number/=n;
        if(num >= 10) res = dict[num] + res ;
        else res = to_string(num) + res;
    }while(number!=0);
    return res;
}

string solution(int n, int t, int m, int p) {
    
    dict[10] = "A";
    dict[11] = "B";
    dict[12] = "C";
    dict[13] = "D";
    dict[14] = "E";
    dict[15] = "F";
    
    string answer = "";
    string n_str;
    int total_cnt = 0, my_cnt = 0;
    int i = 0;
    while(my_cnt < t){
        n_str = to_n(i, n);
        for(int j=0;j<n_str.size()&&my_cnt < t;j++){
            if(total_cnt%m == p-1){
                my_cnt++;
                answer += n_str[j];
            }
            total_cnt++;
        }
        i++;
    }
    return answer;
}