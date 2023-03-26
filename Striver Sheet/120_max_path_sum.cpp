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

int helper(treenode* root , int &maxi){
    if (root == NULL)
    {
        return 0;
    }
    int lp = max(0 , helper(root->left , maxi));
    int rp = max(0 , helper(root->right , maxi));
    int val = root->data;
    maxi = max(maxi , (lp+rp)+val);
    return max(lp , rp) + val;
}

int maxPathSum(treenode* root){
    int maxi = INT_MIN;
    helper(root , maxi);
    return maxi;
}

int main(){
    treenode* root = takeinput();
    cout<<maxPathSum(root)<<endl;
}