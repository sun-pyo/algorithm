#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    priority_queue<int> pq;
    int sum;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
           sum = numbers[i] + numbers[j];
           pq.push(-sum);
        }
    }
    int num = -1;
    while(!pq.empty()){
        if(-pq.top() == num){
            pq.pop();
            continue;
        }
        num = -pq.top();
        pq.pop();
        answer.push_back(num);
    }
    return answer;
}