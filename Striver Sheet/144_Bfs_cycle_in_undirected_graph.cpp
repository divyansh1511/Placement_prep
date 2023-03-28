#include<bits/stdc++.h>
using namespace std;

bool CycleDetectionhelper(int** edges , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[i][node] == 1)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push({i , node});
                }
                else if (par != i)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CycleDetection(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(CycleDetectionhelper(edges , n , i , visited)){
                return true;
            }
        }
    }
    return false;
}

bool cycle_list_helper(vector<vector<int>> edges , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;

    while (!q.empty())
    {
        int nod = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it : edges[nod]){
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it , nod});
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool cycle_list(vector<vector<int>> edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(cycle_list_helper(edges , n , i , visited)){
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
    
    // cout<<CycleDetection(edges , n)<<endl;

    vector<vector<int>> edges(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    cout<<cycle_list(edges , n)<<endl;
}