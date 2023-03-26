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

treenode* helper(vector<int> &in , int inst , int inend , vector<int> post , int pst , int pend){
    if (inst > inend || pst > pend)
    {
        return NULL;
    }
    treenode* root = new treenode(post[pend]);
    int x = inst;
    while (in[x] != post[pend])
    {
        x++;
    }
    root->left = helper(in , inst , x-1 , post , pst , pst+x-inst-1);
    root->right = helper(in , x+1 , inend , post , pst+x-inst , pend-1);
    return root;
}

treenode* BuildTree(vector<int> in , vector<int> post){
    int n = in.size();
    return helper(in , 0 , n-1 , post , 0 , n-1);
}

int main(){

}