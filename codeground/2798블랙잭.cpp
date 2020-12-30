#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int sum3(int a, int b, int c){
    return a+b+c;
}

int main(){
    int N,M, result = 0;
    vector<int> v;
    scanf("%d %d", &N, &M);
    for(int i = 0;i<N;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            if(i==j) continue;
            for(int k=2;k<N;k++){
                if(j==k || i==k) continue;
                if(sum3(v[i], v[j], v[k]) <= M && sum3(v[i], v[j], v[k]) > result ){
                    result = sum3(v[i], v[j], v[k]);
                }
            }
        }
    }
    printf("%d",result);
    v.clear();
    return 0;
}