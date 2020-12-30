#include <iostream>

using namespace std;


int map[1001][1001];
int N_map[1001][1001];
int last_path[1001][1001];

int main(int argc, char** argv)
{
	int T, test_case, H, W, N, x, y , i, j;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>H>>W>>N;
        fill(&N_map[0][0], &N_map[1001][1001], 0);

        for(i=1;i<=H;i++){
            for(j=1;j<=W;j++){
                cin>>map[i][j];
            }
        }

        for(i=1;i<=H;i++){
            for(j=1;j<=W;j++){
                if(i==1 && j==1)
                    N_map[i][j] = N;
                else if(i==1){
                    if(map[i][j-1] == 1){
                        N_map[i][j] = N_map[i][j-1]/2 + N_map[i][j-1]%2;
                    }else{
                        N_map[i][j] = N_map[i][j-1]/2;
                    }
                }
                else if(j == 1){
                    if(map[i-1][j] == 0){
                        N_map[i][j] = N_map[i-1][j]/2 + N_map[i-1][j]%2;
                    }else{
                        N_map[i][j] = N_map[i-1][j]/2;
                    }
                }
                else{
                    if(map[i][j-1] == 1){
                        N_map[i][j] += N_map[i][j-1]/2 + N_map[i][j-1]%2;
                    }else{
                        N_map[i][j] += N_map[i][j-1]/2;
                    }
                    if(map[i-1][j] == 0){
                        N_map[i][j] += N_map[i-1][j]/2 + N_map[i-1][j]%2;
                    }else{
                        N_map[i][j] += N_map[i-1][j]/2;
                    }        
                }
            }
        }
        
        for(i = 1;i<=H;i++){
            for(j=1;j<=W;j++){
                if(N_map[i][j]%2 != 0)
                    last_path[i][j] = map[i][j];
                else
                {
                    last_path[i][j] = map[i][j] ^ 1;
                }
            }
        }

        x=1;
        y=1;
        while(x != W+1 && y != H+1){
            if(last_path[y][x] == 0){
                last_path[y][x] = 1;
                y++;
            }else{
                last_path[y][x] = 0;
                x++;
            }
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << y <<" "<< x << "\n";
	}

	return 0;
}