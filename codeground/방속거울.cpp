#include <iostream>
#include <algorithm>
using namespace std;

int Answer;
char arr[1001][1001];
int visited[1001][1001];
int main(int argc, char** argv)
{
	int T, test_case, x, y, N;
    char d;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        fill(&visited[0][0], &visited[1001][1001],0);
		Answer = 0;
        cin>>N;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                cin>>arr[i][j];
        }
        d = 'R';
        x = 1;
        y = 1;
        while(1<=x && x<=N && 1<=y && y<= N){
            if(arr[y][x] == '1'){
                if(!visited[y][x]){
                    Answer++;
                    visited[y][x]++;
                }   
                if(d == 'R'){
                    d = 'U';
                    y -= 1;
                }else if(d == 'L'){
                    d = 'D';
                    y += 1;
                }else if(d == 'U'){
                    d = 'R';
                    x += 1;
                }else{
                    d = 'L';
                    x -= 1;
                }
            }
            else if(arr[y][x] == '2'){
                if(!visited[y][x]){
                     Answer++;
                     visited[y][x]++;
                }
                if(d == 'R'){
                    d = 'D';
                    y += 1;
                }else if(d == 'L'){
                    d = 'U';
                    y -= 1;
                }else if(d == 'U'){
                    d = 'L';
                    x -= 1;
                }else{
                    d = 'R';
                    x += 1;
                }
            }
            else{
                if(d == 'R'){
                    x += 1;
                }else if(d == 'L'){
                    x -= 1;
                }else if(d == 'U'){
                    y -= 1;
                }else{ 
                    y += 1;
                }
            }
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}