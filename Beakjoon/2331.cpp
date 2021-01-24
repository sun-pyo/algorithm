#include <stdio.h>
#include <vector>

using namespace std;

long long pow(long long num, int p){
    long long result = num;
    for(int i=0;i<p-1;i++){
        result *= num;
    }
    return result;
}

long long get_Dn(long long num, int p){
    long long res = 0;
    while(num != 0){
        res += pow(num%10, p);
        num /= 10;
        
    }
    return res;
}

int main(){
    int P;
    long long A;

    scanf("%lld %d", &A, &P);

    vector<long long> D;
    D.push_back(A);
    long long next;
    int answer;
    bool stop = true;

     while(stop){
        next = get_Dn(D.back(), P);
        for(int i=0;i<D.size();i++){
            if(D[i] == next){
                stop = false;
                answer = i;
                break;
            }
        }
        D.push_back(next);
    }

    printf("%d", answer);   
}
