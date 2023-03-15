#include<bits/stdc++.h>
using namespace std;

double powerofx(double x , int n){
    double ans = 1.0;
    int nn = n;
    if (n < 0)
    {
        nn *= -1;
    }
    
    while (nn)
    {
        if (nn%2)
        {
            ans = ans*x;
            nn = nn-1;
        }
        else
        {
            x = x*x;
            nn = nn/2;
        }
    }
    if (n < 0)
    {
        ans = (double)1.0/(double)ans;
    }
    return ans;
}

int main(){
    cout<<powerofx(2 , 10)<<endl;
}