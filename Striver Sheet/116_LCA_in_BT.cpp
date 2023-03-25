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

treenode* LCA(treenode* root , int x , int y){
    if (root == NULL || root->data == x || root->data == y)
    {
        return root;
    }
    
    treenode* lt = LCA(root->left , x , y);
    treenode* rt = LCA(root->right , x , y);

    if (lt == NULL)
    {
        return rt;
    }
    else if (rt == NULL)
    {
        return lt;
    }
    else
    {
        return root;
    }
}

int main(){
    treenode* root = takeinput();
    cout<<LCA(root , 4 , 5)->data<<endl;
}