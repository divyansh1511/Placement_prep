#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int idx , vector<vector<int>> &ans){
    if (idx == v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        swap(v[i] , v[idx]);
        helper(v , idx+1 , ans);
        swap(v[i] , v[idx]);
    }
}

vector<vector<int>> AllPermutation(vector<int> v){
    vector<vector<int>> ans;
    helper(v , 0 , ans);
    return ans;
}

int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> ans = AllPermutation(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}