#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[] , int n){
    int i = 1 , j = 0;
    while (i < n)
    {
        if (arr[i] == arr[j])
        {
            i++;
        }
        else
        {
            arr[++j] = arr[i];
            i++;
        }
    }
    return j+1;
}

int main(){
    int arr[] = {1,1,2,2,3,4,4};
    int n = removeDuplicate(arr , 7);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}