#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;


int Answer;
vector<pair<int, int>> start[1501];
int del[2001];
int count;
int end_;

int solution(int st,int curr_line, int del_count){
    int i;
    if(st == end_ && start[st].empty()) return 0;
    if(start[end_].empty()) return -1;
    if(start[st].empty()) return -1;
    
    if(st == end_ && start[end_].back().first == curr_line) {
        count = min(count, del_count);
        del[curr_line] = 0;
        return del_count;
    }
   
    if(start[end_].back().first < curr_line) {
        del[curr_line] = 0;
        return -1;
    }
    for(i=0;i<start[st].size();i++){
        if(start[st][i].first <= curr_line || del[start[st][i].first]==1) continue;
        if(solution(start[st][i].second, start[st][i].first, del_count) == 0)
            return 0;
        if(i!=start[st].size()-1){
            del[start[st][i].first] = 1;
        }
            del_count++;
        if(st == end_ && start[end_].back().first == start[st][i].first){
                count = min(count, del_count);
                del[curr_line] = 0;
                return del_count;
            }
    }
    del[curr_line] = 0;
    return -1;
}

int main(int argc, char** argv)
{
	int T, test_case, N, k, m, st, ed, i;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        cin>>N>>k>>m;
        for(i=0;i<k;i++){
            cin>>st>>ed;
            start[st].push_back(make_pair(i, ed));
            start[ed].push_back(make_pair(i, st));
        }
        

        for(i=0;i<m;i++){
            cin>>st>>ed;
            fill(&del[0],&del[2001],0);
            count = INF;
            end_ = ed;
            solution(st,-1,0);
            if(count==INF)
                Answer -= 1;
            else
                Answer += count;
        }

        for(i=0;i<k;i++)
            start[i].clear();

		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;
}