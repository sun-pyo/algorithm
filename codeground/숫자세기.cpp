
#include <iostream>

using namespace std;

int Answer,input;
int main(int argc, char** argv)
{
	int T, test_case, N, i, data;
    
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;
		cin>>N;
		for(i=0;i<N;i++){
            cin>>input;
            Answer ^= input;
		}
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}