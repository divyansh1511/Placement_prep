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

void mirror(treenode* root){
    if (root == NULL)
    {
        return;
    }
    treenode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

int main(){

}