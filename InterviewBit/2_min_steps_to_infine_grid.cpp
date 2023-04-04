#include<bits/stdc++.h>
using namespace std;

int InfineGrid(vector<int> v1 , vector<int> v2){
    int n = v1.size();
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (abs(v1[i] - v1[i+1]) <= abs(v2[i] - v2[i+1]))
        {
            ans += abs(v2[i] - v2[i+1]);
        }
        else
        {
            ans += abs(v1[i] - v1[i+1]);
        }
    }
    return ans;
}

int main(){
    vector<int> v1 = {0 , 1 , 1};
    vector<int> v2 = {0 , 1 , 2};

    cout<<InfineGrid(v1 , v2)<<endl;
}