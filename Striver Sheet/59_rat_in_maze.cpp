#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &m , int n , int x , int y , string tmp , vector<string> &ans){
    if (x < 0 || y < 0 || x >= n || y >= n || m[x][y] == 0)
    {
        return;
    }
    if (x == n-1 && y == n-1)
    {
        ans.push_back(tmp);
        return;
    }
    m[x][y] = 0;
    dfs(m , n , x+1 , y , tmp+'D' , ans);
    dfs(m , n , x-1 , y , tmp+'U' , ans);
    dfs(m , n , x , y-1 , tmp+'L' , ans);
    dfs(m , n , x , y+1 , tmp+'R' , ans);

    m[x][y] = 1;
}

vector<string> Path(vector<vector<int>> &m , int n){
    if (m[0][0] == 0 || m[n-1][n-1] == 0)
    {
        return {"-1"};
    }
    vector<string> ans;
    string tmp = "";
    dfs(m , n , 0 , 0 , tmp , ans);
    return ans;
}

int main(){

}