#include<bits/stdc++.h>
using namespace std;

bool isPowerof2(int n){
    int ans = 1;
    for (int i = 0; i < 32; i++)
    {
        if (ans == n)
        {
            return true;
        }
        if (ans < INT_MAX/2)
        {
            ans = ans*2;
        }
    }
    return false;
}

int main(){

}