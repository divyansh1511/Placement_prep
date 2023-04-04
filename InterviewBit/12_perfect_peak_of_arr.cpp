#include<bits/stdc++.h>
using namespace std;

int Perfect_Peak(int arr[] , int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    int right[n];
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        if (left[i-1] < arr[i] && arr[i] > right[i+1])
        {
            return 1;
        }
    }
    return 0;
}

int main(){

}