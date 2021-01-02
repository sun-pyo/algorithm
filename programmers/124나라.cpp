#include <string>
#include <vector>
#include <cmath>


using namespace std;

string solution(int n) {
    string answer = "";
    int last; 
    while(n!=0){
        last = n%3;
        if(last == 0) last = 3;
        n -= last;
        if(last == 3) last = 4;
        answer = to_string(last) + answer;
        n/=3;
    }
    return answer;
}