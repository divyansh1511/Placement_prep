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

void Inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left , v);
    v.push_back(root->data);
    Inorder(root->right , v);
}

vector<int> pairBST(treenode* root ,int k){
    vector<int> v;
    Inorder(root , v);
    int n = v.size();
    int i = 0 , j = n-1;
    while (i <= j)
    {
        int sum = v[i]+v[j];
        if (sum == k)
        {
            return {i,j};
        }
        else if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {-1,-1};
}

int main(){

}