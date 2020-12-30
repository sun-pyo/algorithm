#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



unsigned long long Answer;

vector<int> A;
vector<int> B;

bool comp(int a,int b){
    return a < b;
}

int main(int argc, char** argv)
{
	int T, test_case, N, K, temp, i;

	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{
        A.clear();
        B.clear();
		Answer = 0;
        cin>>N>>K;
        for(i=0;i<N;i++){
            cin>>temp;
            A.push_back(temp);
        }
        for(i=0;i<N;i++){
            cin>>temp;
            B.push_back(temp);
        }

        sort(A.begin(),A.end(), comp);
        sort(B.begin(),B.end(), comp);
        
        for(i=0;i<K;i++){
            if(Answer < A[i]+B[K-i-1])
                Answer = A[i]+B[K-i-1];
        }

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}