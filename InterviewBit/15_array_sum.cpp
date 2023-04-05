#include<bits/stdc++.h>
using namespace std;

vector<int> ArraySum(vector<int> v1 , vector<int> v2){
    // reverse(v1.begin() , v1.end());
    // reverse(v2.begin() , v2.end());

    vector<int> ans;

    int i = v1.size()-1 , j = v2.size()-1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += v1[i--];
        }
        if (j >= 0)
        {
            sum += v2[j--];
        }
        ans.push_back(sum%10);
        carry = sum/10;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> v1 = {9,9,1};
    vector<int> v2 = {1,2,1};

    vector<int> ans = ArraySum(v1 , v2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}