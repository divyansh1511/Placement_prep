#include<bits/stdc++.h>
using namespace std;

int LCS_3_string(string s1 , string s2 , string s3){
    int n = s1.length() , m = s2.length() , l = s2.length();

    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(m+1 , vector<int>(l+1)));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= l; k++)
            {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                {
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[n][m][l];
}

int main(){
    string s1 = "abab";
    string s2 = "aaab";
    string s3 = "aab";
    cout<<LCS_3_string(s1 , s2 , s3)<<endl;
}