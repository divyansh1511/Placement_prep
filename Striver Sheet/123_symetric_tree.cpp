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

bool helper(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && helper(root1->left , root2->right) && helper(root1->right , root2->left);
}

bool isSymetric(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return helper(root->left , root->right);
}

int main(){
    treenode* root;
    cout<<isSymetric(root)<<endl;
}