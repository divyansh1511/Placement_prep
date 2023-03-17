#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int idx , int t , vector<int> tmp , vector<vector<int>> &ans){
    if (idx == v.size())
    {
        if (t == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[idx] <= t)
    {
        tmp.push_back(v[idx]);
        helper(v , idx , t-v[idx] , tmp , ans);
        tmp.pop_back();
    }
    helper(v , idx+1 , t , tmp , ans);
}

vector<vector<int>> CombinationSum(vector<int> v , int t){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v , 0 , t , tmp , ans);
    return ans;
}

int main(){
    vector<int> v = {2,3,6,7};
    int t = 7;
    vector<vector<int>> ans = CombinationSum(v , t);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}