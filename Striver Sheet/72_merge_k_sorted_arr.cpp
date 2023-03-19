#include<bits/stdc++.h>
using namespace std;

vector<int> mergeksortedarr(vector<vector<int>> v){
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    vector<int> ans = mergeksortedarr(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}