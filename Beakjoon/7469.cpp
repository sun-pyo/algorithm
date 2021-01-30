#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct data_{
    long long num;
    int idx;
};

bool compare(data_ a, data_ b){
    return a.num < b.num;
}

int N, M;
vector<data_> arr;
void Q(int i, int j, int k){
    int count = 0;
    for(int l=0;l<N;l++){
        if(i<=arr[l].idx && arr[l].idx<=j){
            count++;
            if(count == k){
                cout<<arr[l].num<<"\n";
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k;
    vector<int> I,J,K;
    data_ a;
    cin>>N>>M;
    for(int n=0;n<N;n++){
        cin>>a.num;
        a.idx = n + 1;
        arr.push_back(a);
    }

    for(int m=0;m<M;m++){
        cin>>i>>j>>k;
        I.push_back(i);
        J.push_back(j);
        K.push_back(k);
    }
    sort(arr.begin(), arr.end(), compare);

    for(int t=0;t<I.size();t++){
        i = I[t];
        j = J[t];
        k = K[t];
        Q(i, j, k);
    }

}