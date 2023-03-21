#include<bits/stdc++.h>
using namespace std;

int RottenOranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int tot = 0;
    int cnt = 0;
    int days = 0;
    queue<pair<int,int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                tot++;
            }
            if (grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    
    int dx[] = {1 , -1 , 0 , 0};
    int dy[] = {0 , 0 , 1 , -1};

    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x+dx[i] , ny = y+dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return tot == cnt ? days : -1;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<RottenOranges(grid)<<endl;
}