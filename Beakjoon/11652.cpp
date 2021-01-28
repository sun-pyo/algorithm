#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(long long a, long long b){
    return a < b;
}

int main(){
    int N;
    vector<long long> input;
    long long num;
    scanf("%d", &N);

    
    for(int i=0;i<N;i++){
        scanf("%lld", &num);
        input.push_back(num);
    }
    sort(input.begin(), input.end(), compare);

    vector<pair<long long, int>> count;

    for(int i=0;i<input.size();i++){
        if(!count.empty() && count.back().first == input[i]){
            count.back().second++;
        }
        else{
            count.push_back(make_pair(input[i], 1));
        }
    }

    long long answer = input[0];
    int max_count = 0;
    for(int i=0;i<count.size();i++){
        if(max_count == count[i].second){
            if(answer > count[i].first)
                answer = count[i].first;
        }
        else if(max_count < count[i].second){
            max_count = count[i].second;
            answer = count[i].first;
        }
    }

    printf("%lld", answer);
}