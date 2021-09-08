#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node{
    int x, y, num;
}Node;

class Tree{
private:
    Node node;
    Tree *left, *right;
public:
    
    Tree(Node node){
        this->node = node;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    void insert(Node node){
        Tree *curr = this;
        if(node.x < curr->node.x){
            if(curr->left == nullptr) curr->left = new Tree(node);
            else curr->left->insert(node);
        }
        else{
            if(curr->right == nullptr) curr->right = new Tree(node);
            else curr->right->insert(node);
        }
        return;
    }
    
    void preorder(vector<int> &result){
        result.push_back(this->node.num);
        if(this->left != nullptr) this->left->preorder(result);
        if(this->right != nullptr) this->right->preorder(result);
    }

    void postorder(vector<int> &result){
        if(this->left != nullptr) this->left->postorder(result);
        if(this->right != nullptr) this->right->postorder(result);
        result.push_back(this->node.num);
    }
};

bool compare(Node a, Node b){
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{0}};
    vector<Node> node_vector;
    for(int i=0;i<nodeinfo.size();i++){
        Node node;    
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.num = i+1;
        node_vector.push_back(node);
    }
    sort(node_vector.begin(), node_vector.end(), compare);
    Tree *root = new Tree(node_vector[0]);
    for(int i=1;i<node_vector.size();i++){
        root->insert(node_vector[i]);
    }
    vector<int> preorder_result;
    vector<int> postorder_result;
    root->postorder(postorder_result);
    root->preorder(preorder_result);
    answer = {preorder_result, postorder_result};
    return answer;
}
