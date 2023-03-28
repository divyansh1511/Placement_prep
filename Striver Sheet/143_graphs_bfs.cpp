#include<bits/stdc++.h>
using namespace std;

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;

    while (!pendingvertex.empty())
    {
        int curr = pendingvertex.front();
        pendingvertex.pop();
        cout<<curr<<" ";
        for (int i = 0; i < n; i++)
        {
            if (i == curr)
            {
                continue;
            }
            if (!visited[i] && edges[i][curr] == 1)
            {
                visited[i] = true;
                pendingvertex.push(i);
            }
        }
    }
}

void BFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFShelper(edges , n , i , visited);
        }
    }
}

void BFS_list_helper(vector<vector<int>> edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int curr = pendingvertex.front();
        pendingvertex.pop();
        cout<<curr<<" ";
        for (int i = 0; i < n; i++)
        {
            if (i == curr)
            {
                continue;
            }
            if (!visited[i] && edges[i][curr] == 1)
            {
                visited[i] = true;
                pendingvertex.push(i);
            }
        }
    }
}

void BFS_list(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS_list_helper(v , n , i , visited);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    // int** edges = new int*[n];
    // for (int i = 0; i < n; i++)
    // {
    //     edges[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         edges[i][j] = 0;
    //     }
    // }
    // for (int i = 0; i < e; i++)
    // {
    //     int first , second;
    //     cin>>first>>second;
    //     edges[first][second] = 1;
    //     edges[second][first] = 1;
    // }
    
    // BFS(edges , n);

    vector<vector<int>> edges(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    BFS_list(edges , n);
}