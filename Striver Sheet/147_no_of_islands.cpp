#include<bits/stdc++.h>
using namespace std;

void DFShelper(vector<vector<int>> v , int x , int y){
    int n = v.size();
    int m = v[0].size();
    if (x < 0 || x == n || y < 0 || y == n || v[x][y] != 1)
    {
        return;
    }
    v[x][y] = 0;
    DFShelper(v , x+1 , y);
    DFShelper(v , x-1 , y);
    DFShelper(v , x , y+1);
    DFShelper(v , x , y-1);
}

int noofisland(vector<vector<int>> &v){
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                count++;
                DFShelper(v , i , j);
            }
        }
    }
    return count;
}

int main(){
    
}