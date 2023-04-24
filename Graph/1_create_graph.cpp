#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    // int** edges = new int*[n];
    // for (int i = 0; i < n; i++)
    // {
    //     edges[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         edges[i][j] = 0;
    //     }
    // }
    
    // for (int i = 0; i < e; i++)
    // {
    //     int first , second;
    //     cin>>first>>second;
    //     edges[first][second] = 1;
    //     edges[second][first] = 1;
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> v(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
        v[second].push_back(first);
    }
    
    for(int i=0;i<n;i++){
        for(auto it : v[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}