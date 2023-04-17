#include<bits/stdc++.h>
using namespace std;

int SmallerOrEqual(vector<int> v , int k){
    int i = 0 , j = v.size()-1;
    int ans = 0;
    while (i <= j)
    {
        int mid = i + (j-i)/2;
        if (v[mid] > k)
        {
            j = mid-1;
        }
        else
        {
            ans = mid+1;
            i = mid+1;
        }
    }
    return ans;
}

int main(){

}