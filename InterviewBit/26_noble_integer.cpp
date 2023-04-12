#include<bits/stdc++.h>
using namespace std;

int NobleInteger(int arr[] , int n){
    sort(arr , arr+n);

    for (int i = 0; i < n; i++)
    {
        if (i+1 < n && arr[i] != arr[i+1] && arr[i] == n-i-1)
        {
            return 1;
        }
        else if (i == n-1 && arr[i] == 0)
        {
            return 1;
        }
    }
    return -1;
}

int main(){

}