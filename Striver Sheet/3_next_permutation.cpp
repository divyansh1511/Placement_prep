#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &v){
    int n = v.size();
    int l , k;

    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for(l = n-1; l >= 0; l--){
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

int main(){
    vector<int> v = {1,2,3};
    nextPermutation(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}