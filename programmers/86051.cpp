#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int check[10] = {0,};
    for(int num : numbers){
        check[num] = 1;
    }
    for(int i=0;i<10;i++){
        if(check[i] == 0)
            answer += i;
    }
    return answer;
}