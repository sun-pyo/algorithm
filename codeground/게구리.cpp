#include <iostream>
#include <vector>
using namespace std;

int Answer;

vector<unsigned long long> a;
unsigned long long k;

void solution(int N){
    int x = 0;
    for(int i=0;i<N;i++){
        if(i==0){
            if(k < a[i]){
                Answer = -1;
                return;
            }
        }else{
            if(k < a[i]-a[i-1]){
                Answer = -1;
                return;
            }else if(k < a[i]-x){
                Answer++;
                x = a[i-1];
            }
            if(i==N-1)
                Answer++;
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case, N, j;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        a.clear();
        Answer = 0;

        cin>>N;

        for(int i=0;i<N;i++){
            cin>>j;
            a.push_back(j);
        }
        
        cin>>k;
        solution(N);
        
        cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}