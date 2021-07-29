#include <string>
#include <vector>

using namespace std;

int board[100][100] = {0,};

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int winner, loser;
    for(vector<int> v : results){
        winner = v[0] - 1;
        loser = v[1] - 1;
        
        board[winner][loser] = 1;
        board[loser][winner] = -1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(board[j][i] == 1 && board[i][k] == 1){
                    board[j][k] = 1;
                }
                else if(board[j][i] == -1 && board[i][k] == -1){
                    board[j][k] = -1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        bool check = true;
        for(int j=0;j<n;j++){
            if(i!=j && board[i][j] == 0){
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    return answer;
}