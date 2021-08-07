#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int N, M;
vector<string> map;

class Trie{
private:
    Trie* child[26];

public:
    int cnt;
    Trie() : child(), cnt(0) {}
    void insert(string str){
        Trie* curr = this;
        for(char ch : str){
            if(curr->child[ch - 'a'] == nullptr){
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->cnt++;
    }

    int search(string str){
        Trie *curr = this;
        for(int i=0;i<str.size();i++){
            if(curr->child[str[i] - 'a'] == nullptr) return 0;
            curr = curr->child[str[i] - 'a'];
            if(i == str.size()-1){
                return curr->cnt;
            }
        }
        return 0;
    }
};

Trie root;

void dfs(int x, int y, string s){
    s += map[y][x];
    root.insert(s);
    if(s.size() == 5) return;
    int next_x, next_y;
    for(int i=0;i<8;i++){
        next_x = (x + dx[i] + M) % M;
        next_y = (y + dy[i] + N) % N;
        dfs(next_x, next_y, s);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin>>N>>M>>K;
    map.resize(N);
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dfs(j, i, "");
        }
    }
    string str;
    for(int i=0;i<K;i++){
        cin>>str;
        cout<<root.search(str)<<"\n";
    }

}