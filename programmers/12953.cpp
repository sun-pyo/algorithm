#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    int i=1;
    int num = arr.back();
    while(true){
        bool check = true;
        for(int k=0;k<arr.size();k++){
            if( (num*i)%arr[k] != 0) {
                check = false;
                break;
            }
        }
        if(check) return num*i;
        i++;
    }
    return answer;
}