#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int E, S, M, year;

    scanf("%d %d %d", &E, &S, &M);

    year = S;
    while(1){
        if(M == 19 && year % 19 == 0){
            if(E == 15 && year % 15 == 0){
                break;
            }
            else if(year%15 == E){
                break;
            }
        } 
        else if(year%19 == M){
            if(E == 15 && year % 15 == 0){
                break;
            }
            else if(year%15 == E){
                break;
            }
        }
        year += 28;
    }
    printf("%d", year);
}