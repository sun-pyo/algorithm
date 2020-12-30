#include <iostream>

using namespace std;

int rgb[1001][3];
int Answer;

int min_rgb(int idx, int pre_rgb){
    int min_num = 1e9;
    int min_idx = 0;
    for(int i=0;i<3;i++){
        if(pre_rgb != i){
            if(min_num == rgb[idx][i]){
                if(rgb[idx+1][i] > rgb[idx+1][min_idx])
                    min_idx = i;
            }
            else if(min_num > rgb[idx][i]){
                min_num = rgb[idx][i];
                min_idx = i;
            }
        }
    }
    Answer += min_num;
    return min_idx;
}

int main(){
    int N, pre_rgb;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    Answer = 0;
    int min=1e9;
    for(int i=0;i<3;i++){
        if(min > rgb[0][i]){
            min = rgb[0][i];
            pre_rgb = i;
        }
    }
    Answer += min;
    for(int i=1;i<N;i++){
        pre_rgb = min_rgb(i,pre_rgb);
    }
    cout<<Answer<<"\n";
}