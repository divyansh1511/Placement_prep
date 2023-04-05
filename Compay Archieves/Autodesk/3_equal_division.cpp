#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> EqualDivision(vector<int> v){
    unordered_map<int,int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    vector<int> v1 , v2;
    for(auto it : mp){
        if (it.second > 2)
        {
            return {};
        }
        else if (it.second == 2)
        {
            v1.push_back(it.first);
            v2.push_back(it.first);
        }
        else
        {
            v1.size() < v2.size() ? v1.push_back(it.first) : v2.push_back(it.first);
        }
    }
    vector<vector<int>> ans;
    ans.push_back(v1);
    ans.push_back(v2);
    return ans;
}

vector<vector<int>> solution(vector<int> a) {
    unordered_set<int> st1, st2;
    
    for(auto i : a){
        if(st1.count(i) > 0 && st2.count(i) > 0)    return {};
        else{
            if(st1.count(i) > 0)    st2.insert(i);
            else if(st2.count(i) > 0)   st1.insert(i);
            else    (st1.size() <= st2.size()) ? st1.insert(i) : st2.insert(i);
        }
    }
    
    if(st1.size() != st2.size())    return {};
    vector<vector<int>> res;
    vector<int> d1(st1.begin(), st1.end());
    vector<int> d2(st2.begin(), st2.end());
    res.push_back(d1);
    res.push_back(d2);
    return res;
    
}


int main(){
    vector<int> v = {2, 1, 2, 3, 3, 4};
    vector<vector<int>> ans = EqualDivision(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}