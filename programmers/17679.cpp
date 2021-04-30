#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<string> board, int row, int col){
    bool check1, check2, check3;
    check1 = board[row][col] == board[row+1][col];
    check2 = board[row][col] == board[row][col+1];
    check3 = board[row][col] == board[row+1][col+1];
    
    return check1 && check2 && check3;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool end=false;
    vector<string> temp;
    temp.resize(m);
    for(int i=0;i<m;i++) temp[i] = board[i];
    while(!end){
        end = true;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j] != ' ' && check(board, i, j)){
                    end = false;
                    if(temp[i][j] != ' ') answer++;
                    if(temp[i+1][j] != ' ') answer++;
                    if(temp[i][j+1] != ' ') answer++;
                    if(temp[i+1][j+1] != ' ') answer++;
                    temp[i][j] = ' ';
                    temp[i][j+1] = ' ';
                    temp[i+1][j] = ' ';
                    temp[i+1][j+1] = ' ';
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=m-1;j>0;j--){
                if(temp[j][i] == ' '){
                    for(int k=j-1;k>=0;k--){
                        if(temp[k][i] != ' '){
                            char t = temp[k][i];
                            temp[k][i] = temp[j][i];
                            temp[j][i] = t;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++) board[i] = temp[i];
    
    }
    return answer;
}
