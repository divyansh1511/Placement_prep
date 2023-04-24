#include<bits/stdc++.h>
using namespace std;

vector<int> DijkstraAlgo(unordered_map<int,vector<pair<int,int>>> mp , int n , int src){
    vector<int> ans(n , INT_MAX);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    pq.push({0 , src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto it : mp[u]){
            int v = it.first;
            int w = it.second;
            if (ans[v] > ans[u] + w)
            {
                ans[v] = ans[u]+w;
                pq.push({ans[v] , v});
            }
        }
    }
    return ans;
}

int main(){

}