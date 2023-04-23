#include<bits/stdc++.h>
using namespace std;

int LCS(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(res , dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main(){
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    cout<<LCS(s1 , s2 , 6 , 6)<<endl;
}