#include<bits/stdc++.h>
using namespace std;

int RodCuttingPr(vector<int> pr , int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    for(int i=0; i<=n; i++){
        dp[0][i] = i*pr[0];
    }
    
    for(int ind=1; ind<n; ind++){
        for(int length =0; length<=n; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = pr[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[n-1][n];
}

int main(){

}