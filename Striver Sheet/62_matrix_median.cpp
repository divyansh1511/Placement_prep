#include<bits/stdc++.h>
using namespace std;

int Median(vector<vector<int>> &matrix , int row , int col){
    int minele = -1;
    int maxele = -1;

    for (int i = 0; i < row; i++)
    {
        minele = min(minele , matrix[i][0]);
        maxele = max(maxele , matrix[i][col-1]);
    }
    int n = (row * col + 1)/2;
    while (minele < maxele)
    {
        int mid = (minele + maxele)/2;

        int p = 0;
        for (int i = 0; i < row; i++)
        {
            p += upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin();
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
    vector<vector<int>> matrix = {{1,3,5} , {2,6,9} , {3,6,9}};
    cout<<Median(matrix , 3 , 3)<<endl;
}