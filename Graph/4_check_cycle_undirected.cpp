#include<bits/stdc++.h>
using namespace std;

bool cyclehelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    queue<pair<int,int>> pendingvertex;
    pendingvertex.push({sv , -1});
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int nod = pendingvertex.front().first;
        int par = pendingvertex.front().second;
        pendingvertex.pop();
        for(auto it : v[nod]){
            if (!visited[it])
            {
                pendingvertex.push({it , nod});
                visited[it] = true;
            }
            else if (it != par)
            {
                return true;
            }
        }
    }
    return false;
}

bool checkCycle(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cyclehelper(v , n , i , visited))
            {
                return true;
            }
        }   
    }
    return false;
}

//------------------------------------------------------------------------------------------

bool cycleDFS_helper(vector<vector<int>> v , int n , int sv , int par , bool* &visited){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            if(cycleDFS_helper(v , n , it , sv , visited)){
                return true;
            }
        }
        else if (it != par)
        {
            return true;
        }
    }
    return false;
}

bool checkCycleDFS(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cycleDFS_helper(v , n , i, -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){

}