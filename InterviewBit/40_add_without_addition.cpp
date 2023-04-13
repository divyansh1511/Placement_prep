#include<bits/stdc++.h>
using namespace std;

int addnum(int a , int b){
    while (b)
    {
        unsigned carry = a&b;
        a = a^b;
        b = carry << 1;
    }
    return a;
}

int main(){

}