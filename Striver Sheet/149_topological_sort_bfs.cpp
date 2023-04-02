#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(vector<vector<int>> &adj , int n){
    vector<int> indegree(n , 0);

    for(auto it : adj){
        for(auto p : it){
            indegree[p]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    
    vector<int> ans;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        ans.push_back(t);

        for(auto it : adj[t]){
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
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
    
}