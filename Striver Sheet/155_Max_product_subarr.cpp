#include<bits/stdc++.h>
using namespace std;

int MaxProductSubarr(int arr[] , int n){
    int pro = 1;
    int maxpr = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
        if (pro == 0)
        {
            pro = 1;
        }
        maxpr = max(maxpr , pro);
    }
    
    pro = 1;
    for (int i = n-1; i >= 0; i--)
    {
        pro *= arr[i];
        if (pro == 0)
        {
            pro = 1;
        }
        maxpr = max(maxpr , pro);
    }
    return maxpr;
}

int main(){

}