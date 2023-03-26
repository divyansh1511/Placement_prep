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

void FindPreSucc(treenode* root , treenode* &pre , treenode* &succ , int k){
    if (root == NULL)
    {
        return;
    }
    if (root->data == k)
    {
        if (root->left)
        {
            auto tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            pre = tmp;
        }
        if (root->right)
        {
            auto tmp = root->right;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            succ = tmp;
        }
    }
    else if (root->data < k)
    {
        pre = root;
        FindPreSucc(root->right , pre , succ , k);
    }
    else
    {
        succ = root;
        FindPreSucc(root , pre , succ , k);
    }
}

int main(){

}