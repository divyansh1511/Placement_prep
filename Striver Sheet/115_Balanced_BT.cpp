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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            pendingnodes.push(leftchild);
            curr->left = leftchild;
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            pendingnodes.push(rightchild);
            curr->right = rightchild;
        }
    }
    return root;
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right))+1;
}

bool isBalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh-rh) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    treenode* root = takeinput();
    cout<<isBalanced(root)<<endl;
}