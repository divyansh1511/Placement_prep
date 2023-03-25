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

vector<vector<int>> VerticalOrder(treenode* root){
    map<int , map<int,multiset<int>>> mp;
    queue<pair<treenode* , pair<int,int>>> q;

    q.push({root , {0 , 0}});

    while (!q.empty())
    {
        treenode* curr = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        mp[x][y].insert(curr->data);

        if (curr->left)
        {
            q.push({curr->left , {x-1 , y+1}});
        }
        if (curr->right)
        {
            q.push({curr->right , {x+1 , y+1}});
        }
    }
    
    vector<vector<int>> ans;
    for(auto it1 : mp){
        vector<int> col;
        for(auto it2 : it1.second){
            col.insert(col.end() , it2.second.begin() , it2.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    treenode* root = takeinput();
    vector<vector<int>> v = VerticalOrder(root);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}