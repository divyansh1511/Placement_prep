#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int idx , int t , vector<int> tmp , vector<vector<int>> &ans){
    if (t == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > t)
        {
            break;
        }
        tmp.push_back(v[i]);
        helper(v , idx+1 , t-v[i] , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> CombinationSumII(vector<int> v , int t){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v , 0 , t , tmp , ans);
    return ans;
}

int main(){
    vector<int> v = {10,1,2,7,6,1,5};
    int t = 8;
    vector<vector<int>> ans = CombinationSumII(v , t);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}