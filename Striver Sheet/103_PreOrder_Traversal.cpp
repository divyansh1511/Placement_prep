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
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter left child data : "<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            curr->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"Enter right child data : "<<endl;
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

void PreOrderTraversal(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PreOrderTraversalitr(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            cout<<curr->data<<" ";
            st.push(curr->right);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
        }
    }
}

int main(){
    treenode* root = takeinput();
    PreOrderTraversal(root);
    cout<<endl;
    PreOrderTraversalitr(root);
}