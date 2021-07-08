#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> ans_vec;

void sol(string ans, int i, int num, int sum){
    if(i > N) return;
    if(num < 0) num -= i;
    else num += i;
    if(ans.back() == '-'){
        num *= -1;
    }
    ans += to_string(i);

    if(i == N){
        if(sum + num == 0){
            ans_vec.push_back(ans);
        }
        return;
    }
    sol(ans + '+', i+1, 0, sum + num);
    sol(ans + '-', i+1, 0, sum + num);
    sol(ans + ' ', i+1, num*10, sum);
}

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        ans_vec.clear();
        sol("",1, 0, 0);
        sort(ans_vec.begin(), ans_vec.end());
        for(int i=0;i<ans_vec.size();i++){
            cout<<ans_vec[i]<<"\n";
        }
        cout<<"\n";
    }

}