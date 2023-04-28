#include<bits/stdc++.h>
using namespace std;

int solve(int n , int m , vector<vector<int>> v){
    int dp[3][100002];
    memset(dp , 0 , sizeof(dp));

    for(auto it : v){
        dp[--it[0]][it[1]]++;
        dp[it[0]][it[2]+1]++;
    }

    int ans = 0;
    int r = 0 , g = 0 , b = 0;

    for (int i = 0; i <= 100000; i++)
    {
        r += dp[0][i];
        g += dp[1][i];
        b += dp[2][i];

        if(r*g*b > 0){
            ans++;
        }
    }
    return ans;
}

int main(){

}