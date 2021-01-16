#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int N, num;
    scanf("%d", &N);

    vector<int> plus;
    vector<int> minus;

    for(int i=0;i<N;i++){
        scanf("%d",&num);
        if(num < 0)
            minus.push_back(num);
        else
            plus.push_back(num);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end(), compare);

    int answer = 0;
    
    while(!plus.empty()){
        int size = plus.size();
        if(size < 2) break;
        else{
            if(plus[size-1] <= 1 || plus[size-2] <= 1) break;
            int first = plus.back();
            plus.pop_back();
            int second = plus.back();
            plus.pop_back();
            answer += first*second;
        }
    }

    while(!minus.empty()){
        int size = minus.size();
        if(size < 2) break;
        else{
            int first = minus.back();
            minus.pop_back();
            int second = minus.back();
            minus.pop_back();
            answer += first*second;
        }
    }

    while(!plus.empty()){
        int first = plus.back();
        plus.pop_back();
        if(first == 0 && !minus.empty()){
            minus.pop_back();
        }
        else{
            answer += first;
        }
    }
    if(!minus.empty()) answer += minus.back();

    printf("%d", answer);
}