#include<bits/stdc++.h>
using namespace std;

int MatrixSearch(vector<vector<int>> v , int k){
    int n = v.size() , m = v[0].size();

    int st = 0 , en = n*m-1;
    while (st <= en)
    {
        int mid = st + (en-st)/2;
        int x = mid/m;
        int y = mid%m;
        if (v[x][y] == 1)
        {
            return 1;
        }
        if (v[x][y] < 1)
        {
            st = mid+1;
        }
        else
        {
            en = mid-1;
        }
    }
    return 0;
}

int main(){

}