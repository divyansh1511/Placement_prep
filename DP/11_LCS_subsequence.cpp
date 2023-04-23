#include<bits/stdc++.h>
using namespace std;

int LCS(string s1 , string s2 , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (s1[n-1] == s2[m-1])
    {
        return 1 + LCS(s1 , s2 , n-1 , m-1);
    }
    else
    {
        return max(LCS(s1 , s2 , n-1 , m) , LCS(s1 , s2 , n , m-1));
    }
}

int LCS_dp(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout<<LCS(s1 , s2 , 6 , 7)<<endl;
    cout<<LCS_dp(s1 , s2 , 6 , 7)<<endl;
}