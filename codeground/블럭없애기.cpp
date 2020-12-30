/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer=0;

int main(int argc, char** argv)
{
	int T, test_case, N, i;
	cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{   
        Answer=0;
        cin>>N;
        int *h = (int*)calloc(N+2,sizeof(int));
        for(i=1;i<=N;i++){
            cin>>h[i];
        }

        for(i=1;i<=N;i++){
            if(h[i]>h[i-1]+1)
                h[i] = h[i-1]+1;
        }

        for(i=N;i>=1;i--){
            if(h[i]>h[i+1]+1)
                h[i] = h[i+1]+1;

            if(h[i] > Answer)
                Answer = h[i];
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}