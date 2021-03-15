#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1, count = 0;
    priority_queue<int> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    while(true){
        int first = -pq.top();
        if(first >= K) {
            answer = count;
            break;
        }
        else if(pq.size() < 2) break;
        pq.pop();
        int second = -pq.top();
        pq.pop();
        int new_num = first + second*2;
        pq.push(-new_num);
        count++;
    }
    return answer;
}