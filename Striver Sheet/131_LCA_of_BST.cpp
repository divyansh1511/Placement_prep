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

treenode* LCAinBst(treenode* root , treenode* p , treenode* q){
    if (root->data > p->data && root->data > q->data)
    {
        return LCAinBst(root->left , p , q);
    }
    if (root->data < p->data && root->data < q->data)
    {
        return LCAinBst(root->right , p , q);
    }
    return root;
}

int main(){

}