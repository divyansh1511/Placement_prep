#include<bits/stdc++.h>
using namespace std;

int countsubarr(int arr[] , int n , int t){
    unordered_map<int,int> mp;
    int xorr = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
        if (xorr == t)
        {
            c++;
        }
        int h = xorr^t;
        if (mp.find(h) != mp.end())
        {
            c += mp[h];
        }
        mp[xorr]++;
    }
    return c;
}

int main(){
    int arr[] = {4,2,2,6,4};
    cout<<countsubarr(arr , 5 , 6)<<endl;
}