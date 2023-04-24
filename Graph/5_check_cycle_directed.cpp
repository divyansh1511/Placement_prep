#include<bits/stdc++.h>
using namespace std;

bool cyclehelper(vector<vector<int>> v , int sv , bool* &visited , bool* &dfsvisited){
    visited[sv] = true;
    dfsvisited[sv] = true;

    for(auto it : v[sv]){
        if (!visited[it])
        {
            if(cyclehelper(v , it , visited , dfsvisited)){
                return true;
            }
        }
        else if (dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[sv] = false;
    return false;
}

bool checkCycle(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    bool* dfsvisited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dfsvisited[i] = false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cyclehelper(v , i , visited , dfsvisited))
            {
                return true;
            }
        }
    }
    return false;
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
    
}