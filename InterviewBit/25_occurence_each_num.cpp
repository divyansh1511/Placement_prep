#include<bits/stdc++.h>
using namespace std;

vector<int> eachnum(vector<int> v){
    vector<int> ans;
    map<int,int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){

}