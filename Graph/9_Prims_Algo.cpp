#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int> , int>> PrimsAlgo(unordered_map<int , list<pair<int,int>>> mp , int n){
    vector<int> key(n , INT_MAX);
    vector<int> parent(n , -1);
    vector<bool> mst(n , false);

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 0; j < n; j++)
        {
            if (!mst[j] && key[j] < mini)
            {
                mini = key[j];
                u = j;
            }
        }
        mst[u] = true;
        for(auto it : mp[u]){
            int a = it.first;
            int b = it.second;
            if (!mst[a] && b < key[a])
            {
                parent[a] = u;
                key[a] = b;
            }
        }
    }
    vector<pair<pair<int,int> , int>> ans;
    for (int i = 1; i < n; i++)
    {
        ans.push_back({{parent[i] , i} , key[i]});
    }
    return ans;
}

int main(){

}