#include <iostream>

using namespace std;

typedef struct Node{
    char left, right, data;
}Node;

Node node[26];

void preorder(int curr){
    cout<<node[curr].data;
    int left = node[curr].left - 'A';
    int right = node[curr].right - 'A';

    if(left >= 0 && left < 26) preorder(left);
    if(right >= 0 && right < 26) preorder(right);
}

void inorder(int curr){
    int left = node[curr].left - 'A';
    int right = node[curr].right - 'A';

    if(left >= 0 && left < 26) inorder(left);
    cout<<node[curr].data;
    if(right >= 0 && right < 26) inorder(right);
}


void postorder(int curr){
    int left = node[curr].left - 'A';
    int right = node[curr].right - 'A';

    if(left >= 0 && left < 26) postorder(left);
    if(right >= 0 && right < 26) postorder(right);
    cout<<node[curr].data;
}


int main(){
    int N;
    char data, left, right;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>data>>left>>right;
        node[data-'A'].data = data;
        node[data-'A'].left = left;
        node[data-'A'].right = right;
    }
    preorder(0);
    cout<<"\n";
    inorder(0);
    cout<<"\n";
    postorder(0);
}