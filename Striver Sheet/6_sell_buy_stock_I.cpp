#include<bits/stdc++.h>
using namespace std;

int BuyAndSell(int arr[] , int n){
    int minval = INT_MAX;
    int maxval = 0;

    for (int i = 0; i < n; i++)
    {
        minval = min(minval , arr[i]);
        maxval = max(maxval , arr[i]-minval);
    }
    
    return maxval;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    cout<<BuyAndSell(arr , 6)<<endl;
}