#include<bits/stdc++.h>
using namespace std;

void insertsortedly(stack<int> &st , int a){
    if (st.empty() || st.top() < a)
    {
        st.push(a);
        return;
    }
    int b = st.top();
    st.pop();
    insertsortedly(st , a);
    st.push(b);
}

void sortStack(stack<int> &st){
    if (st.empty())
    {
        return;
    }
    int a = st.top();
    st.pop();
    sortStack(st);
    insertsortedly(st , a);
}

int main(){

}