#include <string>
#include <vector>
#include <map>

using namespace std;

vector<char> member;
map<char, int> str_idx;

int abs(int num){
    if(num < 0 ) return -num;
    return num;
}

bool check(char op, int num1, int num2){
    if(op == '=') return num1 == num2;
    else if(op == '>') return num1 > num2;
    else if(op == '<') return num1 < num2;
}

int sol(int idx, vector<int> visit, vector<string> data){
    int res = 0;
    bool v;
    if(idx == 7){
        for(int j=0;j<8;j++){
            v = false;
            for(int i=0;i<idx;i++){
                if(visit[i] == j){
                    v = true;
                    break;
                }
            }
            if(!v){
                visit[idx] = j;
            } 
        }
        for(int i=0;i<data.size();i++){
            int num1 = abs(visit[str_idx[data[i][0]]] - visit[str_idx[data[i][2]]]) -1;
            int num2 = data[i][4] - '0';
            if(!check(data[i][3], num1, num2)) return 0; 
        }
        return 1;
    }

    for(int j=0;j<8;j++){
        v = false;
        for(int i=0;i<idx;i++){
            if(visit[i] == j){
                v = true;
                break;
            }
        }
        if(!v){
            visit[idx] = j;
            res += sol(idx+1, visit, data);
        } 
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    member = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    for(int i=0;i<member.size();i++){
        str_idx[member[i]] = i;
    }
    vector<int> visit = {-1, -1, -1, -1, -1, -1, -1, -1};
    answer = sol(0, visit, data);
    
    return answer;
}