#include<bits/stdc++.h>
using namespace std;

int BalancedArray(int arr[] , int n){
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 += arr[i];
        }
        else
        {
            sum2 += arr[i];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum2 += arr[i];
        }
        else
        {
            sum2 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum1 += arr[i];
        }
    }
    return count;
}

int main(){
    int arr[] = {5, 5, 2, 5, 8};
    cout<<BalancedArray(arr , 5)<<endl;
}