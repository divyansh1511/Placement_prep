#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode(){
        delete left;
        delete right;
    }
};

void Inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left , v);
    v.push_back(root->data);
    Inorder(root->right , v);
}

int main(){
    treenode* root;
    vector<int> v;
    Inorder(root , v);
    cout<<"smallest "<<v[0]<<endl;
    cout<<"largest "<<v[v.size()-1]<<endl;
}