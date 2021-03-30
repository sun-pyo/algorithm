#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int one_count = 0;
    int temp = n;
    while(temp){
        if(temp%2 == 1) one_count++;
        temp/=2;
    }
    answer = n+1;
    while(true){
        temp = answer;
        int one = 0;
        while(temp){
            if(temp%2 == 1) one++;
            temp/=2;
        }
        if(one == one_count) return answer;
        answer++;
    }
    return answer;
}