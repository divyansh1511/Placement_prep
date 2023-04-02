#include<bits/stdc++.h>
using namespace std;

void toposort(vector<vector<int>> &adj , int sv , bool* &visited , stack<int> &st){
    visited[sv] = true;

    for(auto it : adj[sv]){
        if (!visited[it])
        {
            toposort(adj , it , visited , st);
        }
    }
    st.push(sv);
}

vector<int> topologicalsort(vector<vector<int>> adj , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(adj , i , visited , st);
        }
    }
    
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>> v(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
    }
    vector<int> ans = topologicalsort(v , n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}