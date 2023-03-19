#include<bits/stdc++.h>
using namespace std;

vector<int> Freuqentele(vector<int> v , int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto it : mp){
        pq.push({it.second , it.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> v = {1,1,1,2,2,3};
    vector<int> ans = Freuqentele(v , 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}