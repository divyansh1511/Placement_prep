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

treenode* helper(vector<int> &v , int st , int maxi){
    if (st == v.size() || v[st] > maxi)
    {
        return NULL;
    }
    treenode* root = new treenode(v[st]);
    st++;
    root->left = helper(v , st , root->data);
    root->right = helper(v , st , maxi);
    return root;
}

treenode* BSTfrompre(vector<int> v){
    int i = 0;
    return helper(v , i , INT_MAX);
}

int main(){

}