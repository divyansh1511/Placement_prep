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
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            curr->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            curr->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void leftview(treenode* root , vector<int> &ans){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == 0)
            {
                if (curr->left == NULL && curr->right == NULL)
                {
                    continue;
                }
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
}

void rightview(treenode* root , vector<int> &ans){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == n-1)
            {
                if (curr->left == NULL && curr->right == NULL)
                {
                    continue;
                }
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
}

void leafnode(treenode* root , vector<int> &ans){
    if (root == NULL)
    {
        return;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    leafnode(root->left , ans);
    leafnode(root->right , ans);
}

vector<int> BoundaryTraversal(treenode* root){
    vector<int> ans;
    ans.push_back(root->data);
    leftview(root->left , ans);
    leafnode(root , ans);
    rightview(root->right , ans);
    return ans;
}

int main(){
    treenode* root = takeinput();
    vector<int> ans = BoundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}