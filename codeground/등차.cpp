#include <iostream>

using namespace std;

int Answer, M;
unsigned long long b[100000];

void solution(unsigned long long d){
    if(d==0){
        for(int i=0;i<M;i++)
        {
            if(b[0] != b[i])
                return;
        }
        Answer++;
        return;
    }
    else{
        for(int i=1;i<M;i++){
            if((b[i]-b[0]+d)%d != 0)
                return;
        }
        Answer++;
        return;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	int T, test_case;
    unsigned long long d, min_num;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>M;
        Answer = 0;
        for(d=0;d<M;d++){
            cin>>b[d];
            if(d==0)
            {
                min_num = 1000000000000;
            }
            else
                min_num = min(min_num, b[d]-b[d-1]);
        }

        for(d=0;d<=min_num;d++){
            solution(d);
        }
        
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}