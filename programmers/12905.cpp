#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(i-1 >=0 && j-1>=0 && board[i][j] != 0){
                board[i][j] = min(board[i-1][j], min(board[i][j-1], board[i-1][j-1])) + 1;
                if(answer < board[i][j]) answer = board[i][j];
            }
            else if(board[i][j] != 0 && answer < board[i][j]){
                answer = board[i][j];
            }
        }
    }
    
    return answer*answer;
}