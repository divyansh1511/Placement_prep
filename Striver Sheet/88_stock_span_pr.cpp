#include<bits/stdc++.h>
using namespace std;

vector<int> StockSpanPr(vector<int> v){
    stack<int> st;
    int n = v.size();
    vector<int> ans(n , 1);
    st.push(0);
    // ans.push_back(1);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? i+1 : i-st.top();
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v = {100, 80, 60, 70 ,60 ,75 ,85};
    vector<int> ans = StockSpanPr(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}