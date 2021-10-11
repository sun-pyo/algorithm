#include <vector>
#include <iostream>
#include <iostream>

using namespace std;

bool is_answer(vector<int> &A){
    int a = A[0];
    for(int i=1;i<A.size();i++){
        if(a != A[i]) return false;
    }
    return true;
}

int find_min(vector<int> &A, int N){
    int min_ =  A[0], min_idx = 0;
    for(int i=1;i<N;i++){
        if(min_ > A[i]){
            min_ = A[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int add(vector<int> &A, int idx){
    vector<int> left_list, right_list;
    int left=idx, right=idx, num = A[idx];
    for(int i=idx-1;i>=0;i--){
        if(A[i] != num){
            left = i;
            break;
        }
        left_list.push_back(i);
    }
    for(int i=idx;i<A.size();i++){
        if(A[i] != num){
            right = i;
            break;
        }
        right_list.push_back(i);
    }
    int min_lr;
    if(left == idx) min_lr = A[right];
    else if(right == idx) min_lr = A[left];
    else min_lr = min(A[left], A[right]);
    for(int i=0;i<left_list.size();i++){
        A[left_list[i]] = min_lr;
    }
    for(int i=0;i<right_list.size();i++){
        A[right_list[i]] = min_lr;
    }
    return min_lr - num;
}

int main(){
    int N, num, min_idx;
    vector<int> A;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        A.push_back(num);
    }
    long long answer = 0;
    while(!is_answer(A)){
        min_idx = find_min(A, N);
        answer += add(A, min_idx);
    }
    cout<<answer;

}