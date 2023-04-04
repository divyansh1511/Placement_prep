#include<bits/stdc++.h>
using namespace std;

vector<int> Flips(string s){
    int n = s.length();
    int l = -1 , r = -1 , si = 0;
    int curr = 0 , maxsofar = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            curr++;
        }
        else
        {
            curr--;
        }
        if (curr > maxsofar)
        {
            maxsofar = curr;
            l = si , r = i;
        }
        
        if (curr < 0)
        {
            si = i+1;
            curr = 0;
        }
    }
    if (l == -1)
    {
        return {};
    }
    return {l+1 , r+1};
}

int main(){

}