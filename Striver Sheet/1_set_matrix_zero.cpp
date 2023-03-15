#include<bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    bool firstrow = false , firstcol = false;

    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> v = {{1,1,1,1} , {1,0,1,0} , {1,1,1,1}};
    setMatrixZero(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}