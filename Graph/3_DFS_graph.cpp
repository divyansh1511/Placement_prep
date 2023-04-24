#include<bits/stdc++.h>
using namespace std;

void DFShelper(int** edges , int n , int sv , bool* &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
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

//----------------------------------------------------------------------------------------

void DFS_list_helper(vector<vector<int>> v , int n , int sv , bool* &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            DFS_list_helper(v , n , it , visited);
        }
    }
}

void DFS_list(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS_list_helper(v , n , i , visited);
        }
    }
}

int main(){

}