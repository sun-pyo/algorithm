#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K, k=0, ans;
    cin>>N>>K;
    vector<bool> visit(N+1, false);
    for(int i=2;i<=N;i++){
        if(!visit[i]){
            for(int j=1;j*i<=N;j++){
                if(visit[i*j]) continue;
                visit[i*j] = true;
                k++;
                ans = i*j;
                if(k == K){
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
}