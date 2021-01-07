#include <stdio.h>
#include <vector>

using namespace std;

int arr[10];

int main(){
    int N, num;
    scanf("%d",&N);
    vector<int> input;
    
    for(int i =0;i<N;i++){
        scanf("%d",&num);
        input.push_back(num);
    }

    for(int i = 0;i<N;i++){
        int count = 0;
        for(int j=0;j<N;j++){
            if(count == input[i] && arr[j] == 0){
                arr[j] = i+1;
                break;
            }
            if(arr[j] == 0) count++;
        }
    }

    for(int i = 0;i<N;i++)
        printf("%d ",arr[i]);

}