#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int n,m;
int Answer, i;
int visit[201];
int val[201][201];


void sol(int v, int count){

	visit[v] = count % 2 + 1;

	for (int i = 1; i <= n; i++) {
		if (i == v) continue;
		if (val[v][i]) {
			if (!visit[i]) {
				sol(i, count + 1);
			}
			if (visit[i] == visit[v]) {
				Answer = 0;
				return;
			}
		}
		
	}
}


int main(int argc, char** argv)
{
	int T, test_case, count;
    int u, v;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{   
        fill(&val[0][0],&val[200][200],0);
        fill(visit,&visit[200],0);
        cin >> n >> m;
        for(i=0; i<m; i++){
            cin>>u>>v;
            val[u][v] = 1;
            val[v][u] = 1;
        }


        Answer = 1;
        sol(1,0);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;

	}

	return 0;
}