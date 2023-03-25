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

void BottomViewBt(treenode* root){
    queue<pair<treenode* , int>> pendingnodes;
    map<int , int> mp;
    pendingnodes.push({root, 0});

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front().first;
            int h = pendingnodes.front().second;
            pendingnodes.pop();
            mp[h] = curr->data;
            if (curr->left)
            {
                pendingnodes.push({curr->left , h-1});
            }
            if (curr->right)
            {
                pendingnodes.push({curr->right , h+1});
            }
        }
    }
    
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

int main(){
    treenode* root = takeinput();
    BottomViewBt(root);
}