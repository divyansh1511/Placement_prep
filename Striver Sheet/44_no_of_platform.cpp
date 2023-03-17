#include<bits/stdc++.h>
using namespace std;

int NoofPlatform(int arr[] , int dept[] , int n){
    sort(arr , arr+n);
    sort(dept , dept+n);

    int ans = 1;
    int count = 1;
    int i=1 , j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dept[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans = max(ans , count);
    }
    return ans;
}

int main(){
    
}