#include<bits/stdc++.h>
using namespace std;

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingnodes;
    pendingnodes.push(sv);
    visited[sv] = true;
    while (!pendingnodes.empty())
    {
        int curr = pendingnodes.front();
        pendingnodes.pop();
        cout<<curr<<" ";
        for (int i = 0; i < n; i++)
        {
            if (i == curr)
            {   
                continue;
            }
            if (edges[curr][i] == 1 && !visited[i])
            {
                pendingnodes.push(i);
                visited[i] = true;
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

//-------------------------------------------------------------------------------

void BFS_list_helper(vector<vector<int>> v , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;

    while (!pendingvertex.empty())
    {
        int curr = pendingvertex.front();
        pendingvertex.pop();
        cout<<curr<<" ";
        for(auto it : v[curr]){
            if (!visited[it])
            {
                pendingvertex.push(it);
                visited[it] = true;
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
    
}