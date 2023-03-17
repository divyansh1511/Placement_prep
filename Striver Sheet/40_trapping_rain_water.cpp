#include<bits/stdc++.h>
using namespace std;

int TrappingRainWater(vector<int> v){
    int n = v.size();
    int left[n] , right[n];
    left[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , v[i]);
    }
    right[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i] , right[i])-v[i]);
    }
    return ans;
}

int TrappingRainWater_m2(vector<int> v){
    int ml = 0 , mr = 0;
    int sum = 0;
    int n = v.size();
    int i = 0 , j = n-1;

    while (i <= j)
    {
        if (v[i] <= v[j])
        {
            if (v[i] >= ml)
            {
                ml = v[i];
            }
            else
            {
                sum += (ml-v[i]);
            }
            i++;
        }
        else
        {
            if (v[j] >= mr)
            {
                mr = v[j];
            }
            else
            {
                sum += (mr-v[j]);
            }
            j--;
        }
    }
    return sum;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<TrappingRainWater_m2(v)<<endl;
}