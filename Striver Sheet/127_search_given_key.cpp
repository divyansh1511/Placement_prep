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

bool searchinBST(treenode* root , int k){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if (root->data < k)
    {
        return searchinBST(root->right , k);
    }
    if (root->data > k)
    {
        return searchinBST(root->left , k);
    }
    return false;
}

int main(){

}