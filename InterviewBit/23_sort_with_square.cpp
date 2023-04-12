#include<bits/stdc++.h>
using namespace std;

vector<int> sortwithsquare(vector<int> &v){
    int n = v.size();
    int i = 0 , j = n-1;
    vector<int> ans(n);

    for (int k = n-1; k >= 0; k--)
    {
        if (abs(v[i]) > abs(v[j]))
        {
            ans[k] = v[i] * v[i];
            i++;
        }
        else
        {
            ans[k] = v[j] * v[j];
            j--;
        }
    }
    return ans;
}

int main(){

}