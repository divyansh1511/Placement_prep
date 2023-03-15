#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[] , int n){
    int z = 0 , o = 0 , t = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            z++;
        }
        else if (arr[i] == 1)
        {
            o++;
        }
        else
        {
            t++;
        }
    }
    int i = 0;
    for (i ; i < z; i++)
    {
        arr[i] = 0;
    }
    for (i ; i < (z+o); i++)
    {
        arr[i] = 1;
    }
    for (i ; i < n; i++)
    {
        arr[i] = 2;
    }
    
}

int main(){
    int arr[] = {1,1,0,2,0,2};
    sort012(arr , 6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}