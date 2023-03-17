#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n-2; i++)
    {
        if (i>0 && v[i] == v[i-1])
        {
            continue;
        }
        int j = i+1 , k = n-1;
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum == 0)
            {
                ans.push_back({v[i] , v[j] , v[k]});
                while (j<k && v[j] == v[j+1])
                {
                    j++;
                }
                while (j<k && v[k] == v[k-1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = ThreeSum(v);
    // cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}