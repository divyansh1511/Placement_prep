#include<bits/stdc++.h>
using namespace std;

void merge_m1(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    
    while (i<=k && j<m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k] , arr2[j]);
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
}

void merge_m2(int arr1[] , int arr2[] , int n , int m){
    
    int gap = ceil((float)(n+m)/2);

    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < (n+m))
        {
            if (j<n && arr1[i] > arr1[j])
            {
                swap(arr1[i] , arr1[j]);
            }
            else if (i<n && j>=n && arr1[i] > arr2[j-n])
            {
                swap(arr1[i] , arr2[j-n]);
            }
            else if (i>=n && j>=n && arr2[i-n] > arr2[j-n])
            {
                swap(arr2[i-n] , arr2[j-n]);
            }
            i++;
            j++;
        }
        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil((float) gap / 2);
        }
    }
}

int main(){
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8};
    merge_m2(arr1 , arr2 , 5 , 4);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr1[i]<<" ";
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<arr2[i]<<" ";
    }
    
}