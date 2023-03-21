#include<bits/stdc++.h>
using namespace std;

int minchrs(string s){
    int n = s.length();
    int i = 0 , j = n-1;
    int k = n;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            while (s[j] != s[0])
            {
                j--;
            }
            k = j;
            i = 0;
        }
    }
    if (k == n)
    {
        return 0;
    }
    return n-k-1;
}

int main(){
    cout<<minchrs("AACECAAAA")<<endl;
}