#include<bits/stdc++.h>
using namespace std;

int minLights(int arr[] , int n , int k){
    int i = 0;
    int curr = -1;
    int cnt = 0;
    while (i < n)
    {
        curr = -1;
        for (int j = max(0 , i-k+1); j < min(n , i+k); j++)
        {
            if (arr[j] == 1)
            {
                curr = j;
            }
        }
        if (curr == -1)
        {
            return -1;
        }
        cnt++;
        i = curr+k;
    }
    return cnt;
}

int main(){
    int arr[] = { 0, 0, 1, 1, 1, 0, 0, 1};
    cout<<minLights(arr , 8 , 3)<<endl;
}