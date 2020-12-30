#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> bucket;
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        int doll = 0; 
        int curr_move = moves[i] - 1;
        for(int j = 0; j< board.size();j++){ 
            if(board[j][curr_move] == 0 ) continue;
            doll = board[j][curr_move];
            board[j][curr_move] = 0;
            break;
        }
        if(doll != 0 ){
            if(bucket.empty())
                bucket.push_back(doll);
            else{
                if(bucket.back() == doll)
                {
                    bucket.pop_back();
                    answer+=2;
                }else{
                    bucket.push_back(doll);
                }
            }
        }
    }
    return answer;
}
int main(){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    printf("%d", solution(board, moves));
}