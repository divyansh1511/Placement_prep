#include<bits/stdc++.h>
using namespace std;

vector<int> FindOnes(int A , vector<vector<int>> Q){
    vector<int> ans;
    vector<int> v(A , 1);
    
    for(auto it : Q){
        if (it[0] == 0)
        {
            v[it[1]-1] = 0;
        }
        else if (it[0] == 1)
        {
            int c = 0;
            bool flag = false;
            for (int i = 0; i < A; i++)
            {
                if (v[i] == 1)
                {
                    c++;
                    if (c == it[1])
                    {
                        ans.push_back(i+1);
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
            {
                ans.push_back(-1);
            }
        }
    }
    return ans;
}

int main(){
    int A = 5;
    vector<vector<int>> Q = {{0, 3}, {1, 4}, {0, 3}, {1, 5}};
    vector<int> output = FindOnes(A, Q);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
}