#include <vector>
#include <iostream>

using namespace std;

int sum[100000] = {0,};

int main(){
    int N, num;
    vector<int> card;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        card.push_back(num);
    }

    sum[0] = card[0];
    sum[1] = card[1];

    for(int i=2;i<N;i++){
        sum[i] = sum[i-2] + card[i];
    }

    int answer = sum[N-2];
    int temp_sum;
    for(int i=0;i<N;i++){
        if(i%2 == 0){
            temp_sum = sum[i] + sum[N-1] - card[i];
            if(i>0) temp_sum -= sum[i-1];
            answer = max(answer, temp_sum);
        }
        else{
            temp_sum = sum[i-1] + sum[N-1] - card[N-1];
            if(i >= 2) temp_sum -= sum[i-2];
            answer = max(answer, temp_sum);
        }
    }
    cout<<answer<<"\n";
}