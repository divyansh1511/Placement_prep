#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AntiDiagonals(vector<vector<int>> mat){
    int n = 2*(mat.size())-1;
    vector<vector<int>> v(n);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            v[i+j].push_back(mat[i][j]);
        }
    }
    return v;
}

int main(){
    vector<vector<int>> mat = {{1,2,3} , {4,5,6} , {7,8,9}};
    vector<vector<int>> ans = AntiDiagonals(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}