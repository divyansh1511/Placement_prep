#include<bits/stdc++.h>
using namespace std;

int longestsubarr(int arr[] , int n){
    int sum = 0;
    unordered_map<int,int> mp;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            l = max(l , i+1);
        }
        else if (mp.find(sum) != mp.end())
        {
            l = max(l , i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return l;
}

int main(){
    int arr[] = {9, -3, 3, -1, 6, -5};
    cout<<longestsubarr(arr , 6)<<endl;
}