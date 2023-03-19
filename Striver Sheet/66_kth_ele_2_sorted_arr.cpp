#include<bits/stdc++.h>
using namespace std;

int Kthelement2sortedarr(int arr1[] , int arr2[] , int n , int m , int k){
    if (n > m)
    {
        return Kthelement2sortedarr(arr2 , arr1 , m , n , k);
    }
    int lo = max(0 , k-m) , hi = min(k , n);

    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = k-cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1 , l2);
        }
        else if (l1 > r2)
        {
            hi = cut1-1;
        }
        else
        {
            lo = cut1+1;
        }
    }
    return 1;
}

int main(){
    int arr1[] = {2,3,6,7,9};
    int arr2[] = {1,4,8,10};
    cout<<Kthelement2sortedarr(arr1 , arr2 , 5 , 4 , 5)<<endl;
}