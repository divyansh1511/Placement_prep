#include<bits/stdc++.h>
using namespace std;

vector<int> MaximumSum(vector<int> a , vector<int> b , int c){ 
    priority_queue<int,vector<int>, greater<int>> pq;

    sort(a.begin() , a.end() , greater<int>());
    sort(b.begin() , b.end() , greater<int>());

    for (int i = 0; i < c; i++)
    {
        pq.push(a[i]+b[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (i != j)
            {
                if ((a[i]+b[j]) >= pq.top())
                {
                    pq.pop();
                    pq.push(a[i]+b[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> a = {1,4,2,3};
    vector<int> b = {2,5,1,6};
    vector<int> ans = MaximumSum(a , b , 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}