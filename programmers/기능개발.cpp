#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int num;
    
    int count = 1;
    int max_day =  (100-progresses[0])/speeds[0];
    if((100-progresses[0])%speeds[0] != 0) max_day++;
    int day;
    for(int i = 1;i<progresses.size();i++){
        
        day = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i] != 0) day++;
        
        if(max_day<day){
            answer.push_back(count);
            count = 1;
            max_day = day;
        }
        else{
            count++;
        }
    }
    answer.push_back(count);
    
    
    return answer;
}