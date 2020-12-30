#include <iostream>

using namespace std;

int Answer;

int score[101][101];
int total[101][101][11];
int N, M, K;

void solution(int x, int y,int pre_s, int w, int t_s){ 
    if((M+N-x-y) < w){
        return;
    }
    else if(x == M && y == N){
        t_s += abs(pre_s- abs(score[x][y]));
        Answer = min(Answer, t_s);
        return;
    }

    if(score[x][y] < 0)
        w--;

    t_s += abs(pre_s-abs(score[x][y]));

    if(x < M)
        solution(x+1,y, abs(score[x][y]), w, t_s);
    if(y < N)
        solution(x,y+1, abs(score[x][y]), w, t_s);
}


int main(int argc, char** argv)
{
	int T, test_case,i,j,num;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>M>>N;
        cin>>K;
        for(i=0;i<=N;i++){
            for(j=0;j<=M;j++){
                cin>>score[j][i];
            }
        }
		Answer = 100000000;

        solution(1,0,score[0][0],K,0);
        solution(0,1,score[0][0],K,0);


		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}