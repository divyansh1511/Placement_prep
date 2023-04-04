#include<bits/stdc++.h>
using namespace std;

vector<int> addonetonum(vector<int> v){
    reverse(v.begin() , v.end());
    int carry = 1;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i] + carry;
        v[i] = sum%10;
        carry = sum/10;
    }
    if (carry != 0)
    {
        v.push_back(carry);
    }
    reverse(v.begin() , v.end());
    return v;
}

int main(){
    vector<int> v = {9,9,9};
    vector<int> ans = addonetonum(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}