#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterEle(vector<int> v){
    int n = v.size();
    vector<int> tmp(n , -1);
    stack<int> st;
    for (int i = 2*n-1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i%n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
            {
                tmp[i] = st.top();
            }
        }
        st.push(v[i%n]);
    }
    return tmp;
}

int main(){

}