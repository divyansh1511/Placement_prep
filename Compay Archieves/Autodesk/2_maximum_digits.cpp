// Given an array of integers a, your task is to calculate the digits that occur the most number of times in the array.
// Return the array of these digits in ascending order

#include<bits/stdc++.h>
using namespace std;

vector<int> MaximumDigits(vector<int> v){
    vector<int> t(10 , 0);
    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i];
        while (a)
        {
            int tmp = a%10;
            a /= 10;
            t[tmp]++;
        }
    }
    
    int maxi = *max_element(t.begin() , t.end());
    vector<int> ans;
    for (int i = 0; i < 10; i++)
    {
        if (t[i] == maxi)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    vector<int> v = {25, 2, 3, 57, 38, 41};
    vector<int> ans = MaximumDigits(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}