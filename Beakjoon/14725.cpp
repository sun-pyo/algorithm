#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Tree{
private:
    map<string, Tree*> child;
    string level;

public:
    Tree() : child(), level("") {}
    
    void insert_line(vector<string> line){
        Tree *curr = this;
        int i = 0;
        for(string s : line){
            if(curr->child.find(s) == curr->child.end()){
                curr->child[s] = new Tree();
            }
            if(i++ != 0) curr->child[s]->level = "--" + curr->level;
            curr = curr->child[s];
        }
    }

    void traversal(){
        Tree* curr = this;
        map<string, Tree*>::iterator iter;
        for(iter=curr->child.begin();iter!=curr->child.end();iter++){
            cout<<iter->second->level<<iter->first<<"\n";
            iter->second->traversal();
        }
    }
};

int main(){
    int N, K;
    string s;
    Tree root;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>K;
        vector<string> st; 
        for(int k=0;k<K;k++){
            cin>>s;
            st.push_back(s);
        }
        root.insert_line(st);
    }
    root.traversal();
}