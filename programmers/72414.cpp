#include <string>
#include <vector>

using namespace std;

int timeToSec(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h*60*60 + m*60 + s;
}

string secToTime(int sec){
    char res[10];
    sprintf(res, "%02d:%02d:%02d", sec/3600, sec/60%60, sec%60);
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play_time_sec, adv_time_sec, start_sec, end_sec; 
    
    play_time_sec = timeToSec(play_time);
    adv_time_sec = timeToSec(adv_time);
    vector<int> total_time(play_time_sec+1, 0);
    
    for(string log : logs){
        start_sec = timeToSec(log.substr(0, 8));
        end_sec = timeToSec(log.substr(9, 8));
        
        for(int i=start_sec;i<end_sec;i++){
            total_time[i]++;
        }
    }
    
    int answer_sec=0;
    long long sum = 0, max_sum;
    for(int j=0;j<adv_time_sec;j++){
        sum += total_time[j];
    }
    max_sum = sum;
    for(int adv_end=adv_time_sec;adv_end<play_time_sec;adv_end++){
        sum = sum + total_time[adv_end] - total_time[adv_end-adv_time_sec];
        if(max_sum < sum){
            answer_sec = adv_end - adv_time_sec + 1;
            max_sum = sum;
        }
    }
    answer = secToTime(answer_sec);
    
    return answer;
}