#include<bits/stdc++.h>
using namespace std;

bool DFS_cycle_helper(int** edges , int n , int sv , int par , bool* &visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[i][sv] == 1)
        {
            if (!visited[i])
            {
                DFS_cycle_helper(edges , n , i , sv , visited);
            }
            else if (par != i)
            {
                return true;
            }
        }
    }
    return false;
}

bool DFS_cycle(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(DFS_cycle_helper(edges , n , i , -1 , visited)){
                return true;
            }
        }
    }
    return false;
}

bool DFS_list_helper(vector<vector<int>> edges , int n , int sv , int par , bool* &visited){
    visited[sv] = true;
    for(auto it : edges[sv]){
        if (!visited[it])
        {
            DFS_list_helper(edges , n , it , sv , visited);
        }
        else if (par != it)
        {
            return true;
        }
    }
    return false;
}

bool DFS_list(vector<vector<int>> edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(DFS_list_helper(edges , n , i , -1 , visited)){
                return true;
            }
        }
    }
    return false;
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
    
    // cout<<DFS_cycle(edges , n)<<endl;

    vector<vector<int>> edges(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    cout<<DFS_list(edges , n)<<endl;
}