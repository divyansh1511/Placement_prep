#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> nums){
    int n = nums.size();
    vector<int> v(n , 1);
    for (int i = 1; i < n; i++)
    {
        v[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && v[i] < v[j]+1)
            {
                v[i] = v[j]+1;
            }
        }
    }
    return *max_element(v.begin() , v.end());
}

int main(){

}