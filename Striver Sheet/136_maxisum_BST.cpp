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

class nodeval{
    public:
    int maxnode;
    int minnode;
    int size;

    nodeval(int minnode , int maxnode , int size){
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->size = size;
    }
};

nodeval* helper(treenode* root){
    if (root == NULL)
    {
        return new nodeval(INT_MAX , INT_MIN , 0);
    }
    
    auto l = helper(root->left);
    auto r = helper(root->right);

    if (l->maxnode < root->data && root->data < r->minnode)
    {
        return new nodeval(min(root->data , l->minnode) , max(root->data , r->maxnode) , l->size+r->size+1);
    }
    return new nodeval(INT_MIN , INT_MAX , max(l->size , r->size));
}

int LargestBSTinBT(treenode* root){
    return helper(root)->size;
}

int main(){

}