#include<bits/stdc++.h>
using namespace std;

vector<int> TwoSum(int arr[] , int n , int t){
    unordered_map<int,int> mp;
    // int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(t-arr[i]) != mp.end())
        {
            return {mp[t-arr[i]] , i};
        }
        mp[arr[i]] = i;
    }
    return {-1 , -1};
}

int main(){
    int arr[] = {2,7,11,15};
    vector<int> v = TwoSum(arr , 4 , 9);
    
    cout<<v[0]<<" "<<v[1]<<endl;
}