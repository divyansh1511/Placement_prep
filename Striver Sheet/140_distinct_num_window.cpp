#include<bits/stdc++.h>
using namespace std;

vector<int> DNum(vector<int> v , int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[v[i]]++;
    }
    vector<int> ans;
    v.push_back(mp.size());
    for (int i = k; i < v.size(); i++)
    {
        mp[v[i-k]]--;
        if (mp[v[i-k]] == 0)
        {
            mp.erase(v[i-k]);
        }
        mp[v[i]]++;
        v.push_back(mp.size());
    }
    return v;
}

int main(){

}