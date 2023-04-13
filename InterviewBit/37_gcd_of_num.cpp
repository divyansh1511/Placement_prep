#include<bits/stdc++.h>
using namespace std;

int Gcd(int a , int b){
    if (a == 0)
    {
        return b;
    }
    return Gcd(b%a , a);
}

int main(){

}