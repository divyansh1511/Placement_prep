#include<bits/stdc++.h>
using namespace std;

void DFShelper(int** edges , int n , int sv , bool* &visited){
    visited[sv] = true;
    cout<<sv<<" ";
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (!visited[i] && edges[i][sv] == 1)
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFS_list_helper(vector<vector<int>> &edges , int n , int sv , bool* &visited){
    visited[sv] = true;
    cout<<sv<<" ";
    for(auto it : edges[sv]){
        if (!visited[it])
        {
            DFS_list_helper(edges , n , it , visited);
        }
    }
}

void DFS_list(vector<vector<int>> &edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS_list_helper(edges , n , i , visited);
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
    
    // DFS(edges , n);

    vector<vector<int>> edges(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    DFS_list(edges , n);
}