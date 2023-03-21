#include<bits/stdc++.h>
using namespace std;

string LongestPrefix(vector<string> v){
    int n = v.size();
    if (n == 0)
    {
        return "";
    }
    sort(v.begin() , v.end());
    string a = v[0];
    string b = v[n-1];
    string ans = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
        ans += a[i];
    }
    return ans;
}

int main(){
    vector<string> v = {"flower","flow","flight"};
    cout<<LongestPrefix(v)<<endl;
}