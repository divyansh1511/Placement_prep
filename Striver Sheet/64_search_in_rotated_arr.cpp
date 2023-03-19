#include<bits/stdc++.h>
using namespace std;

int search(int arr[] , int n , int k){
    int i = 0;
    int j = n;

    while (i <= j)
    {
        int mid = (i+j)/2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[i] <= arr[mid])
        {
            if (arr[i] <= k && arr[mid] >= k)
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
            if (arr[mid] <= k && k <= arr[j])
            {
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2,3};
    cout<<search(arr , 8 , 0)<<endl;
}