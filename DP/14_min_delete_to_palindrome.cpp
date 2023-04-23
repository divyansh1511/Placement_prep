#include<bits/stdc++.h>
using namespace std;

int LPS(string s1){
    string s2 = s1;
    reverse(s2.begin() , s2.end());
    int n = s1.length();

    int dp[n+1][n+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int mindelete(string s){
    int n = s.length();
    return n - LPS(s);
}

int main(){
    string s = "aebcbda";
    cout<<mindelete(s)<<endl;
}