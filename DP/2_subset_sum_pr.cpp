#include<bits/stdc++.h>
using namespace std;

bool SubsetsumPr(int arr[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (arr[n-1] <= sum)
    {
        return SubsetsumPr(arr , n-1 , sum-arr[n-1]) || SubsetsumPr(arr , n-1 , sum);
    }
    else
    {
        return SubsetsumPr(arr , n-1 , sum);
    }
}

bool SubsetsumPr_dp(int arr[] , int n , int sum){
    bool dp[n+1][sum+1];
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    cout<<SubsetsumPr(arr , 6 , 9)<<endl;
    cout<<SubsetsumPr_dp(arr , 6 , 9)<<endl;
}