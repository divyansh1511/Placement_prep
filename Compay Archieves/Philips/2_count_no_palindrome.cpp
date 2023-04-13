#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string t){
    int i = 0 , j = t.length()-1;
    while (i <= j)
    {
        if (t[i] != t[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int CountPrime(string s){
    string tmp = "";
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if(isPalindrome(tmp)){
                c++;
            }
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
    }
    return c;
}

int main(){

}