#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> v , int n , int st , int end){
    bool* visited = new bool[n];
    unordered_map<int , int> parent;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    q.push(st);
    visited[st] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto it : v[curr]){
            if (!visited[it])
            {
                visited[it] = true;
                parent[it] = curr;
                q.push(it);
            }
        }
    }
    
    vector<int> ans;
    int curr = end;
    ans.push_back(end);
    while (curr != st)
    {
        curr = parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){

}