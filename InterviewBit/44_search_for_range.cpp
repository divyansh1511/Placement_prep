#include<bits/stdc++.h>
using namespace std;

int findFirstindex(vector<int> v, int key)
{
    int i = 0, j = v.size() - 1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (v[mid] == key)
        {
            ans = mid;
            j = mid - 1;
        }
        else if (v[mid] < key)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return ans;
}

int lastindex(vector<int> v, int key)
{
    int i = 0, j = v.size() - 1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (v[mid] == key)
        {
            ans = mid;
            i = mid + 1;
        }
        else if (v[mid] < key)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    // int n = nums.size();
    int a = findFirstindex(nums, target);
    if (a == -1)
    {
        return {-1, -1};
    }
    int b = lastindex(nums, target);
    return {a, b};
}

int main(){
    
}