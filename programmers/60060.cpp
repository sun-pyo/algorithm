#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie{
private:
    Trie* child[26];
    int cnt;
    
public:
    Trie() : child(), cnt(0){}
    
    void Insert(string str){
        Trie* curr = this;
        
        for(char ch : str){
            curr->cnt++;
            
            if(curr->child[ch-'a'] == nullptr) curr->child[ch-'a'] = new Trie();
            curr = curr->child[ch-'a'];
        }
        curr->cnt++;
    }
    
    int Search(string str){
        Trie* curr = this;
        
        for(char ch : str){
            if(ch == '?') return curr->cnt;
            
            curr = curr->child[ch-'a'];
            if(curr == nullptr) return 0;
        }
        return 0;
    }
};

Trie trie[10000];
Trie reverse_trie[10000];


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(string s : words){
        trie[s.size()-1].Insert(s);
        reverse(s.begin(), s.end());
        reverse_trie[s.size()-1].Insert(s);
    }
    
    for(string q : queries){
        if(q[0] != '?') answer.push_back(trie[q.size()-1].Search(q));
        else{
            reverse(q.begin(), q.end());
            answer.push_back(reverse_trie[q.size()-1].Search(q));
        }
    }
    return answer;
}