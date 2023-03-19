#include<bits/stdc++.h>
using namespace std;

double multiply(int num , int n){
    double a = 1.0;
    for (int i = 0; i < n; i++)
    {
        a *= num;
    }
    return a;
}

double NthRoot(int n, int m){
    double i = 1;
    double j = m;
    double eps = 1e-7;

    while (j-i > eps)
    {
        double mid = (i+j)/2.0;
        if (multiply(mid , n) < m)
        {
            i = mid;
        }
        else
        {
            j = mid;
        }
    }
    return i;
}

int main(){
    cout<<NthRoot(2 , 16)<<endl;
}