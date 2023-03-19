#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<string> board , int row , int col){
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col ; i >= 0 && j >= 0; i-- , j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col; i >= 0 && j < board.size(); i-- , j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void helper(vector<string> &board , int row , vector<vector<string>> &ans){
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (isvalid(board , row , i))
        {
            board[row][i] = 'Q';
            helper(board , row+1 , ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> NqueenProblem(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n , '.'));
    helper(board , 0 , ans);
    return ans;
}

int main(){
    vector<vector<string>> ans = NqueenProblem(4);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    
}