#include<bits/stdc++.h>
using namespace std;

int countsubset(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int targetSum(int arr[] , int n , int target){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum < target || (sum+target)%2 == 1)
    {
        return 0;
    }
    return countsubset(arr , n , (sum+target)/2);
}

int main(){
    int arr[] = {1,1,1,1,1};
    cout<<targetSum(arr , 5 , 3)<<endl;
}