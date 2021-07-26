#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    vector<vector<int>> r_key = key;
    int M = key.size();
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            r_key[j][M-1-i] = key[i][j];
        }
    }
    return r_key;
}

bool check_lock(vector<vector<int>>lock){
    int N = lock.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(lock[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> check;
    for(int k=0;k<4;k++){
        for(int i=-M;i<N;i++){
            for(int j=-M;j<N;j++){
                check = lock;
                for(int key_y=0;key_y<M;key_y++){
                    for(int key_x=0;key_x<M;key_x++){
                        if(key_y+i >= 0 && key_y+i<N && key_x+j>=0 && key_x+j<N){
                            check[key_y+i][key_x+j] += key[key_y][key_x];
                        }
                    }
                }
                if(check_lock(check)) return true;
            }
        }
        key = rotate(key);
    }
        
    return false;
}