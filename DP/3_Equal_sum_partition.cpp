#include<bits/stdc++.h>
using namespace std;

bool subsetsum_pr(int arr[] , int n , int sum){
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

bool EqualSumPartition(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum%2 != 0)
    {
        return false;
    }
    return subsetsum_pr(arr , n , sum/2);
}

int main(){
    int arr[] = {1,5,11,5};
    cout<<EqualSumPartition(arr , 4)<<endl;
}