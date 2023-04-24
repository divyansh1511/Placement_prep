#include<bits/stdc++.h>
using namespace std;

void toposort(vector<vector<int>> v , int sv , bool* &visited , stack<int> &st){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            toposort(v , it , visited , st);
        }
    }
    st.push(sv);
}

vector<int> Topologicalsort(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(v , i , visited , st);
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

//---------------------------------------------------------------------------------------------

vector<int> toposort_BFS(vector<vector<int>> v , int n){
    int* indegree = new int[n];
    for (int i = 0; i < n; i++)
    {
        for(auto it : v[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto it : v[a]){
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
    int n , e;
    cin>>n>>e;
    vector<vector<int>> v;
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
    }

}