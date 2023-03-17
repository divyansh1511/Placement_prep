#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int idx , vector<int> &tmp , vector<vector<int>> &ans){
    if (idx == v.size())
    {
        ans.push_back(tmp);
        return;
    }
    tmp.push_back(v[idx]);
    helper(v , idx+1 , tmp , ans);
    tmp.pop_back();
    helper(v , idx+1 , tmp , ans);
}

vector<vector<int>> AllSubsets(vector<int> v){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v , 0 , tmp , ans);
    sort(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> v = {1,2,2};
    vector<vector<int>> ans = AllSubsets(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}