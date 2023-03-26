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

treenode* helper(vector<int> v , int st , int end){
    if (st > end)
    {
        return NULL;
    }
    int mid = (st+end)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper(v , st , mid-1);
    root->right = helper(v , mid+1 , end);
    return root;
}

treenode* arrtoBST(vector<int> v){
    int i = 0 , j = v.size()-1;
    return helper(v , i , j);
}

int main(){

}