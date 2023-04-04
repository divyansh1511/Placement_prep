#include<bits/stdc++.h>
using namespace std;

int Partitions(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum%3 != 0)
    {
        return 0;
    }
    sum /= 3;
    int s = 0 , count = 0 , left = 0;

    for (int i = 0; i < n-1; i++)
    {
        s += arr[i];
        if (s == 2*sum)
        {
            count += left;
        }
        if (s == sum)
        {
            left++;
        }
    }
    return count;
}

int main(){
    int arr[] = {1, 2, 3, 0, 3};
    cout<<Partitions(arr , 5)<<endl;
}