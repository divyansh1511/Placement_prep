#include<bits/stdc++.h>
using namespace std;

string ReverseWords(string s){
    string ans = "";
    string tmp = "";
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(tmp);
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
    }
    if (tmp != "")
    {
        st.push(tmp);
    }
    
    while (!st.empty())
    {
        ans += st.top();
        ans += " ";
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    getline(cin , s);
    cout<<ReverseWords(s)<<endl;
}