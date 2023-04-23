#include<bits/stdc++.h>
using namespace std;

int Knapsack01_recur(int wt[] , int val[] , int n , int W){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(Knapsack01_recur(wt , val , n-1 , W-wt[n-1]) + val[n-1] , Knapsack01_recur(wt , val , n-1 , W));
    }
    else
    {
        return Knapsack01_recur(wt , val , n-1 , W);
    }
}

int Knapsack01_Dp(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int wt[] = {4,5,1};
    int val[] = {1,2,3};
    cout<<Knapsack01_recur(wt , val , 3 , 4)<<endl;
    cout<<Knapsack01_Dp(wt , val , 3 , 4)<<endl;
}