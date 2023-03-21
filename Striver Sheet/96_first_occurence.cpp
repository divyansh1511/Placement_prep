#include<bits/stdc++.h>
using namespace std;

int FirstOccurence(string s , string n){
    int a = s.length();
    int b = n.length();
    if (n == "")
    {
        return 0;
    }
    if (b > a)
    {
        return -1;
    }
    for (int i = 0; i < a-b+1; i++)
    {
        if (s.substr(i , b) == n)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    cout<<FirstOccurence("sadbutsad" , "sad")<<endl;
}