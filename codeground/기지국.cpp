/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, r, L, n, i, j,idx;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        idx = -1;
		cin>>n;
		cin>>r>>L;
        Answer = 0;
        int *x = (int*)malloc(sizeof(int)*n);
        int *check = (int*)calloc(L,sizeof(int));
        for(i=0;i<n;i++){
            cin>>x[i];
            for(j=x[i]-r;j<=x[i]+r;j++){
                if(0<=j && j<=L)
                    check[j]++;
            }
        }
        
        sort(x,x+n);
        
        for(i=0;i<=L;i++){
            if(x[idx+1] == i) idx++;
            if(check[i] == 0){
                if(idx != -1 && x[idx]-r< 0 || check[x[idx]-r] > 1){
                    check[x[idx]-r]--;
                    x[idx]++;
                    check[x[idx]+r]++;
                    Answer++;
                }else{
                        while(i != x[idx+1]-r){
                        check[x[idx+1]+r]--;
                        x[idx+1]--;
                        check[x[idx+1]-r]++;
                        Answer++;
                    }
                }
            }
        }
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
		free(x);
		free(check);
	}

	return 0;//Your program should return 0 on normal termination.
}