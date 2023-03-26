#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &img , int i , int j , int val , int newcolor){
    if (i<0 || i >= img.size() || j < 0 || j >= img[i].size() || img[i][j] == newcolor || img[i][j] != val)
    {
        return;
    }
    img[i][j] = newcolor;
    dfs(img , i-1 , j , val , newcolor);
    dfs(img , i+1 , j , val , newcolor);
    dfs(img , i , j-1 , val , newcolor);
    dfs(img , i , j+1 , val , newcolor);
}

vector<vector<int>> FloodFill(vector<vector<int>> &img , int sr , int sc , int newcolor){
    int val = img[sr][sc];
    dfs(img , sr , sc , val , newcolor);
    return img;
}

int main(){

}