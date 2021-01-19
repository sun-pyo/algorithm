#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compare[50][50];

int main(){
    vector<string> A;
    vector<string> B;
    int N, M, bit;
    scanf("%d %d", &N, &M);
    A.resize(N+1);
    B.resize(N+1);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }         

    for(int i=0;i<N;i++){
        cin>>B[i];
        for(int j=0;j<M;j++){
            compare[i][j] = A[i][j] -'0' ^  B[i][j] -'0';
        }
    }

    int answer = 0;
    if(N>=3 && M>=3){
        for(int i=0;i<N-2;i++){
            for(int j=0;j<M-2;j++){
                if(compare[i][j] == 1){
                    answer++;
                    for(int y=0;y<3;y++){
                        for(int x=0;x<3;x++){                 
                                compare[y+i][x+j] = compare[y+i][x+j] ^ 1;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        {
            if(compare[i][j] == 1){
                answer = -1;
                break;
            }
        }
    }
    
    printf("%d",answer);
}