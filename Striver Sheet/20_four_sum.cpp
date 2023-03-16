#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> FourSum(vector<int> v , int t){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n-3; i++)
    {
        for (int j = i+1; j < n-2; j++)
        {
            int k = j+1 , l = n-1;
            while (k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum == t)
                {
                    ans.push_back({v[i] , v[j] , v[k] , v[l]});
                    
                    while (k < l && v[k] == v[k+1])
                    {
                        k++;
                    }
                    while (k < l && v[l] == v[l-1])
                    {
                        l--;
                    }
                    
                    k++;
                    l--;
                }
                else if (sum < t)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = FourSum(v , 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}