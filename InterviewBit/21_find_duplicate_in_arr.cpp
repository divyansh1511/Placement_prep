#include<bits/stdc++.h>
using namespace std;

int FindDuplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]) - 1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return arr[ind];
        }
    }
    return -1;
}

int main(){

}