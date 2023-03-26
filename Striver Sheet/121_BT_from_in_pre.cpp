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

treenode* helper(vector<int> pre , int &prest , vector<int> in , int inst , int inend){
    if (inst > inend)
    {
        return NULL;
    }
    treenode* root = new treenode(pre[prest]);
    int idx = inst;
    while (in[idx] != pre[prest])
    {
        idx++;
    }
    prest++;
    root->left = helper(pre , prest , in , inst , idx-1);
    root->right = helper(pre , prest , in , idx+1 , inend);
    return root;
}

treenode* BuildTree(vector<int> pre , vector<int> in){
    int n = pre.size();
    int prest = 0;
    return helper(pre , prest , in , 0 , n-1);
}

void LevelOrderTraversal(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            cout<<curr->data<<" ";
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<int> preorder{10,20,40,50,30,60};
    vector<int> inorder{40,20,50,10,60,30};
    treenode* root = BuildTree(preorder, inorder);
    LevelOrderTraversal(root);
}