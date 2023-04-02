#include<bits/stdc++.h>
using namespace std;

bool dfs(int node , int col , vector<int> v , vector<vector<int>> adj){
    v[node] = col;

    for(auto it : adj[node]){
        if (v[it] == -1)
        {
            if (dfs(it , !col , v , adj) == false)
            {
                return false;
            }
        }
        else if (v[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBiparatite(int n , vector<vector<int>> adj){
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == -1)
        {
            if (dfs(i , 0 , v , adj) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main(){

}