#include<bits/stdc++.h>
using namespace std;

int FindDuplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i])-1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return arr[i];
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,4,2,2};
    cout<<FindDuplicate(arr , 5)<<endl;
}