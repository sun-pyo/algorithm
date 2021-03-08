#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<pair<int,int>> bridge_on;
    while(true){
        answer++;
        int size = bridge_on.size();
        for(int i=0;i<size;i++){
            int len = bridge_on.front().first;
            int w = bridge_on.front().second;
            bridge_on.pop();
            if(len <= 1){
                sum -= w;
            }
            else{
                bridge_on.push(make_pair(len-1, w));
            }
        }
        if(truck_weights.size() > 0 && sum + truck_weights[0] <= weight){
            bridge_on.push(make_pair(bridge_length,truck_weights[0]));
            sum += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
        if(bridge_on.size() == 0 && truck_weights.size() == 0) break;
    }
    return answer;
}

int main(){
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    cout<<solution(bridge_length, weight, truck_weights);
}