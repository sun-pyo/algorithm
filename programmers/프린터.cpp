// https://programmers.co.kr/learn/courses/30/lessons/42587


#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int num = priorities[location];
    int exist[10] = {0,};
    queue<int> q;
    for(int i = 0;i<priorities.size();i++){
        if(i == location)
            q.push(-1);
        else
            q.push(priorities[i]);
        exist[priorities[i]]++;
    }
    int max = 9;
    while(!q.empty()){
        if(exist[max] == 0){
            max--;
        }else{
            if(q.front() == -1 ){
                if(num == max){
                    answer++;
                    break;
                }
                q.pop();
                q.push(-1);
            }
            else if(q.front() == max){
                exist[max]--;
                q.pop();
                answer++;
            }else{
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    return answer;
}