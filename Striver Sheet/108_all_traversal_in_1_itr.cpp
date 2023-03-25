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
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter left child data"<<endl;
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

void helper(treenode* root , vector<int> &in , vector<int> &pre , vector<int> &post){
    stack<pair<treenode* , int>> st;
    if (root == NULL)
    {
        return;
    }
    st.push({root , 1});

    while (!st.empty())
    {
        treenode* curr = st.top().first;
        int h = st.top().second;
        st.pop();

        if (h == 1)
        {
            pre.push_back(curr->data);
            h++;
            st.push({curr , h});
            if (curr->left)
            {
                st.push({curr->left , 1});
            }
        }
        
        else if (h == 2)
        {
            in.push_back(curr->data);
            h++;
            st.push({curr , h});
            if (curr->right)
            {
                st.push({curr->right , 1});
            }
        }
        
        else
        {
            post.push_back(curr->data);
        }
    }
}

void AllTraversal(treenode* root){
    vector<int> in;
    vector<int> pre;
    vector<int> post;

    helper(root , in , pre , post);
    int n = in.size();

    for (int i = 0; i < n; i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<post[i]<<" ";
    }
}

int main(){
    treenode* root = takeinput();
    AllTraversal(root);
}