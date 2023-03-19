#include<bits/stdc++.h>
using namespace std;

int singleElement(int arr[] , int n){
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
    }
    return xorr;
}

int singleElement2(int arr[] , int n){
    int i = 0;
    int j = n-2;

    while (i <= j)
    {
        int mid = (i+j)/2;
        if (mid%2 == 0)
        {
            if (arr[mid] != arr[mid+1])
            {
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid+1])
            {
                j = mid-1;
            }
            else
            {
                i = mid+1; 
            }
        }
    }
    return arr[i];
}

int main(){
    int arr[] = {1,1,2,3,3,4,4,8,8};
    cout<<singleElement2(arr , 9)<<endl;
}