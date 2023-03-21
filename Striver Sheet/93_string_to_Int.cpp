#include<bits/stdc++.h>
using namespace std;

int atoi1(string s){
    int res = 0;
    int n = s.length();
    int ind = 1;
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    while (s[i] == ' ' && i<n)
    {
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        ind = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while ('0' <= s[i] && s[i] <= '9' && i<n)
    {
        res = res*10 + s[i]-'0';
        i++;
    }
    return res*ind;
} 

int main(){
    cout<<atoi1("   -43")<<endl;
}