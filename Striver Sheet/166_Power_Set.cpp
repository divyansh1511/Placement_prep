#include<bits/stdc++.h>
using namespace std;

void PowerSet(int i, string s , string &tmp){
    if (i == s.length())
    {
        cout<<tmp<<" ";
        return;
    }
    tmp = tmp+s[i];
    PowerSet(i+1 , s , tmp);
    tmp.pop_back();
    PowerSet(i+1 , s , tmp);
}

int main(){

}