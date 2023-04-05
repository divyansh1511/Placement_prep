// You are given an array of positive integers arr. You'd like to know how many triangles can be formed with side lengths equal to adjacent elements from arr.

// Construct an array of integers of length arr.length - 2, where the ith element is equal to 1 if it's possible to form a triangle with side lengths arr[i], arr[i + 1], and arr[i + 2], otherwise 0.

// Return the resulting array of integers.

// Note: A triangle can be formed with side lengths a, b, and c if a + b > c, a + c > b, and b + c > a.

#include<bits/stdc++.h>
using namespace std;

vector<int> TrianglePossible(vector<int> v){
    int n = v.size();
    if (n < 3)
    {
        return {};
    }
    vector<int> ans;
    for (int i = 0; i < n-2; i++)
    {
        int s1 = v[i] , s2 = v[i+1] , s3 = v[i+2];
        if (s1+s2 > s3 && s1+s3 > s2 && s2+s3 > s1)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,2,2,4};
    vector<int> ans = TrianglePossible(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}