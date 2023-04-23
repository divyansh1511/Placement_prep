#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[] , int n){
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
    }
    return *max_element(dp , dp+n);
}

int main(){
    int arr[] = {10,9,2,5,3,7,101,18};
    cout<<LIS(arr , 8)<<endl;
}