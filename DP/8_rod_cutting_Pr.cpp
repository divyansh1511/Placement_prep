#include<bits/stdc++.h>
using namespace std;

int RodCuttingPr(int prices[] , int n){
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i+1;
    }
    int dp[n+1][n+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (length[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j-length[i-1]] + prices[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

int main(){
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<RodCuttingPr(prices , 8)<<endl;
}