#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

unsigned long long min_Answer, max_Answer;
int K;
queue<int> q;

void solution(unsigned long long n, int k){
    if(k==K){
        min_Answer = min(min_Answer, n);
        max_Answer = max(max_Answer, n);
        return;
    }

    if((n-1)/3 > 1 && (n-1)%3 == 0 && ((n-1)/3)%2 != 0){
        
        solution((n-1)/3,k+1);
    }

    solution(n*2, k+1);
}

int main(int argc, char** argv)
{
	int T, test_case, i;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

        min_Answer = 1000000000;
        max_Answer = 0;
        cin>>K;
        if(K==0){
            min_Answer = 1;
            max_Answer = 1;
        }
        else
        {
            solution(1,0);
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << min_Answer <<" "<< max_Answer << "\n";
	}

	return 0;
}