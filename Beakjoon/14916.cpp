#include <iostream>

using namespace std;

int main(){
    int total, total_temp;
    cin>>total;
    int coin5, coin2;
    coin5 = total/5;
    for(int i=coin5;i>=0;i--){
        if( (total - 5*i)%2 == 0 ){
            coin2 = (total-5*i)/2;
            cout<<i+coin2<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
}