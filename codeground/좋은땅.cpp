/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;


int Answer,i,j;
int d[300][300];
int T, test_case,k,m, temp,N,M,total;
int main(int argc, char** argv)
{
	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        d[300][300] = {0,};
	    temp=0;
        total = 0;

        cin>>N>>M;
        
        for(i=0;i<N;i++){
            for(j=0;j<M;j++)
                cin>>d[i][j];
        }
        
    total = 0;
    if(M<5 && N<5)
    {
        for(i=0;i<N;i++){
            for(j=0;j<M;j++)
                total += d[i][j];
        }    
    }
    else{
        for(k=0;M-k>=5;k++){
            for(m=0;N-m>=5;m++){
                
                for(i=k;i<5+k;i++){
                    for(j=m;j<5+m;j++)
                        temp += d[i][j];
                }        
                total = max(temp,total);
                temp = 0;
            }
        }
    }           
    
        
		cout << "Case #" << test_case+1 << "\n";
		cout << total << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}