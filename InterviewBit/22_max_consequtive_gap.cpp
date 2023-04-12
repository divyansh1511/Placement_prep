#include<bits/stdc++.h>
using namespace std;

int maxconsequtivegap(int arr[] , int n){
    sort(arr , arr+n);
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans = max(ans , arr[i+1]-arr[i]);
    }
    return ans;
}

int main(){

}