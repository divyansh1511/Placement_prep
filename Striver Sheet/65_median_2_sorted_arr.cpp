#include<bits/stdc++.h>
using namespace std;

int Medianof2arr(int arr1[] , int arr2[] , int n , int m){
    if (n > m)
    {
        return Medianof2arr(arr2 , arr1 , m , n);
    }
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m+n)%2 != 0)
            {
                return max(l1 , l2);
            }
            else
            {
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
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
    return 0.0;
}

int main(){
    int arr1[] = {1,4,7,10,12};
    int arr2[] = {2,3,6,15};
    cout<<Medianof2arr(arr1 , arr2 , 5 , 4)<<endl;
}