#include<bits/stdc++.h>
using namespace std;

int Knapsack(int wt[] , int val[] , int n , int W){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(Knapsack(wt , val , n , W-wt[n-1]) + val[n-1] , Knapsack(wt , val , n-1 , W));
    }
    else
    {
        return Knapsack(wt , val , n-1 , W);
    }
}

int KnapsackDp(int wt[] , int val[] , int n , int W){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1] , dp[i-1][j]); 
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
    int wt[] = {5,10,15};
    int val[] = {10 , 30 , 20};
    cout<<Knapsack(wt , val , 3 , 100)<<endl;
    cout<<KnapsackDp(wt , val , 3 , 100)<<endl;
}