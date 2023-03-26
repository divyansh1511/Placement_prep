#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
    ~TreeNode(){
        delete left;
        delete right;
    }
};

class BSTIterator {
    private:
        stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        find_left(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->val;
    }
    
    bool hasNext() {
        if(st.empty()){
            return false;
        }
        return true;
    }
    void find_left(TreeNode* root)
    {
        TreeNode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

int main(){
    
}