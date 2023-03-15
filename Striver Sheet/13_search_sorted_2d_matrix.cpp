#include<bits/stdc++.h>
using namespace std;

bool searchinmatrix(vector<vector<int>> v , int k){
    int n = v.size();
    int m = v[0].size();

    int i = 0 , j = n*m-1;

    while (i <= j)
    {
        int mid = (i+j)/2;
        int x = v[mid/m][mid%m];
        if (x == k)
        {
            return true;
        }
        else if (x < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> v = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12}};
    cout<<searchinmatrix(v , 10)<<endl;
}