#include<bits/stdc++.h>
using namespace std;

int Majority_element(int arr[] , int n){
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
        }
        if (candidate == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main(){
    int arr[] = {1,2,3,2,2};
    cout<<Majority_element(arr , 5)<<endl;
}