#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<arr1.size();i++){
        int num = arr1[i] | arr2[i];
        string s = "";
        for(int j=0;j<arr1.size();j++){
            if(num%2 == 1) s = "#" + s;
            else s = " " + s;
            num /= 2;
        }
        answer.push_back(s);
        
    }
    return answer;
}