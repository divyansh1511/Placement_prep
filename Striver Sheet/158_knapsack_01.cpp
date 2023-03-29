#include<bits/stdc++.h>
using namespace std;

int Knapsack(int wt[] , int val[] , int n , int W){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
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
    cout<<Knapsack(wt , val , 3 , 4)<<endl;
}