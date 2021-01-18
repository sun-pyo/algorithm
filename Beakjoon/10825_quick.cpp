#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string name;
    int korean_score;
    int english_score;
    int math_score;
} student;


int partition(vector<student>& arr, int left, int right){
    int low = left+1, high = right;
    student p = arr[left];
    while(low <= high){
        while(low<=right){
            if(arr[low].korean_score > p.korean_score){
                low++;
            }
            else if(arr[low].korean_score == p.korean_score){
                if(arr[low].english_score < p.english_score){
                    low++;
                }
                else if(arr[low].english_score == p.english_score){
                    if(arr[low].math_score > p.math_score){
                        low++;
                    }
                    else if(arr[low].math_score == p.math_score){
                        if(arr[low].name < p.name){
                            low++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }

        while(high > left){
            if(arr[high].korean_score < p.korean_score){
                high--;
            }
            else if(arr[high].korean_score == p.korean_score){
                if(arr[high].english_score > p.english_score){
                    high--;
                }
                else if(arr[high].english_score == p.english_score){
                    if(arr[high].math_score < p.math_score){
                        high--;
                    }
                    else if(arr[high].math_score == p.math_score){
                        if(arr[high].name > p.name){
                            high--;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }

        if(low<high){
            student temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;

        }
        
    } 

    student temp = arr[high];
    arr[high] = p;
    arr[left] = temp;

    return high;
}

void quicksort(vector<student>& arr, int left, int right){
    if(left < right){
        

        int p = partition(arr, left, right);


        quicksort(arr, left, p-1);
        quicksort(arr, p+1, right);
    }
}

int main(){
    vector<student> arr;
    int N;
    scanf("%d",&N);

    arr.resize(N);

    for(int i = 0;i<N;i++){
        cin>>arr[i].name;
        scanf(" %d %d %d", &arr[i].korean_score, &arr[i].english_score, &arr[i].math_score);
    }     

    quicksort(arr, 0, N-1);

    for(int i = 0;i<N;i++)
        cout<<arr[i].name<<"\n";
    
}