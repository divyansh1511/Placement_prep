#include<bits/stdc++.h>
using namespace std;

int MatrixMedian(vector<vector<int>> v){
    int minele = -1 , maxele = -1;
    int n = v.size() , m = v[0].size();

    for (int i = 0; i < n; i++)
    {
        minele = min(minele , v[i][0]);
        maxele = max(maxele , v[i][m-1]);
    }
    
    int tmp = (n*m+1)/2;
    while (minele < maxele)
    {
        int mid = minele + (maxele-minele)/2;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            p += upper_bound(v[i].begin() , v[i].end() , mid) - v[i].begin();
        }
        if (p < n)
        {
            minele = mid+1;
        }
        else
        {
            maxele = mid;
        }
    }
    return minele;
}

int main(){

}