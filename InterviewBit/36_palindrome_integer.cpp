#include<bits/stdc++.h>
using namespace std;

bool PalindromeInt(int n){
    int a = 0;
    int tmp = n;
    while (n)
    {
        a = a*10 + n%10;
        n = n/10;
    }
    if (a == tmp)
    {
        return true;
    }
    return false;
}

int main(){

}