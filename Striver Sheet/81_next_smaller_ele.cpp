#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallerele(vector<int> v){
    int n = v.size();
    vector<int> a(n , -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > v[i])
        {
            st.pop();
        }
        a[i] = st.empty() ? -1 : st.top();
        st.push(v[i]);
    }
    return a;
}

int main(){
    vector<int> v = {4, 5, 2, 10, 8};
    vector<int> ans = NextSmallerele(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}