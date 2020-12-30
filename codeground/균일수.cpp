#include <iostream>
#include <cmath>
using namespace std;



unsigned long long N, n, b, k;
int i;

bool solution(){
    i = 0;
    n = N;
    
    while(n){
        if(i==0)
        {
            i=1;
            k = n%b;
        }
        if(n%b != k)
            return false;
        n /= b;
    }
    return true;
}

int main(int argc, char** argv)
{
	int T, test_case, check;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        bool flag = false;
        cin>>N;
		
        cout << "Case #" << test_case+1 <<"\n";

        if(N == 2)
        {
            b = 3;
            cout << b <<"\n";
            continue;
            
        }
        else if(N==1 || N==3){
            b = 2;
            cout << b <<"\n";
            continue;
        }

        for(b = 2;b<=sqrt(N);b++){
            if(flag = solution())
                break;
        }

        if(!flag){
            for(k=sqrt(N);k >= 1;k--){
                if(N%k == 0 && N/k - 1 >= sqrt(N)){
                    flag = true;
                    b = N/k - 1; 
                    break;
                }
            }
        }

        if(!flag)
            b = N-1;

		cout << b <<"\n";
	}

	return 0;
}