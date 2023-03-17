#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int tmp , int idx , vector<int> &ans){
    if (idx == v.size())
    {
        ans.push_back(tmp);
        return;
    }
    helper(v , tmp+v[idx] , idx+1 , ans);
    helper(v , tmp , idx+1 , ans);
}

vector<int> subsetsum(vector<int> v){
    int tmp = 0;
    vector<int> ans;
    helper(v , tmp , 0 , ans);
    sort(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> v = {5,2,1};
    vector<int> ans = subsetsum(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}