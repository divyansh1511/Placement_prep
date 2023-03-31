#include<bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int> v , int sum , int n){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (v[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool canPartition(vector<int> v){
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    if (sum%2 != 0)
    {
        return false;
    }
    return subsetsum(v , sum/2 , n);
}

int main(){

}