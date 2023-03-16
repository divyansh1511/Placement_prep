#include<bits/stdc++.h>
using namespace std;

int longestsubstring(string s){
    vector<int> v(256 , -1);
    int left = 0 , right = 0;
    int n = s.length();
    int len = 0;
    while (right < n)
    {
        if (v[s[right]] != -1)
        {
            left = max(left , v[s[right]]+1);
        }
        v[s[right]] = right;

        len = max(len , right-left+1);
        right++;
    }
    return len;
}

int main(){
    string s = "abcabcbb";
    cout<<longestsubstring(s)<<endl;
}