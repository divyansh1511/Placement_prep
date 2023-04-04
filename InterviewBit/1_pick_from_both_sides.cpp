#include<bits/stdc++.h>
using namespace std;

int Pickfromsides(int arr[] , int n , int k){
    int sum = 0;
    int i = 0;
    for (i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    i--;
    int ans = sum;
    int j = n-1;
    while (i >= 0)
    {
        sum += arr[j--];
        sum -= arr[i--];
        ans = max(ans , sum);
    }
    return ans;
}

int main(){
    int arr[] = {5, -2 , 3 , 1 , 2};
    int k = 3;
    cout<<Pickfromsides(arr , 5 , 3)<<endl;
}