#include<bits/stdc++.h>
using namespace std;

vector<int> PrimeSum(int n){
    vector<bool> v(n+1 , true);
    v[0] = v[1] = false;

    for (int i = 2; i*i <= n; i++)
    {
        for (int j = i*i; j <= n; j += i)
        {
            v[j] = false;
        }
    }
    
    for (int i = 2; i < n; i++)
    {
        if (v[i] && v[n-i])
        {
            return {i , n-i};
        }
    }
    return {};
}

int main(){

}