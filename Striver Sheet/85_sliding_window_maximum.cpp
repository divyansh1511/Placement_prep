#include<bits/stdc++.h>
using namespace std;

vector<int> SlidingWindowMaximum(vector<int> v , int k){
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < v.size(); i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            ans.push_back(v[dq.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = SlidingWindowMaximum(v , 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}