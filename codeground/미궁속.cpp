#include <iostream>

using namespace std;

int  N, K;
unsigned long long Answer;
char input_string[300000];

int solution(int n){
    int result = 0;
    for(int i = 1;i<n;i++){
        if(i<=N)
            result += i;
        else{
            result += 2*N - i;
        }
    }
    return result;
}

int main(int argc, char** argv)
{
	int T, test_case, i, x, y;
	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        scanf("%d %d",&N, &K);
        scanf("%s",input_string);
        x = 1;
        y = 1;
		Answer = 1;
        for(i=0;i<K;i++){
            if(input_string[i] == 'U'){
                y -= 1;
            }
            else if(input_string[i] == 'D'){
                y += 1;
            }
            else if(input_string[i] == 'R'){
                x += 1;
            }
            else{
                x -= 1;
            }
            Answer += solution(x+y-1);
            if(x+y-1 <= N){
                if((x+y-1)%2 == 0){
                    Answer += y;
                }
                else
                    Answer += x;
            }
            else{
                if((x+y-1)%2 == 0){
                    Answer += N-x+1;
                }
                else
                    Answer += N-y+1;
            }
        }

		cout << "Case #" << test_case+1 << "\n";
		cout<<Answer<<"\n";
	}

	return 0;
}