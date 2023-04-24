#include<bits/stdc++.h>
using namespace std;

int bellmanford(int n , int sv , int end , int v , vector<vector<int>> edges){
    vector<int> dist(n+1 , INT_MAX);

    dist[sv] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int a = edges[j][0];
            int b = edges[j][1];
            int wt = edges[j][2];

            if (dist[a] != INT_MAX && ((dist[a]+wt) < dist[b]))
            {
                dist[b] = dist[a]+wt;
            }
        }
    }
    return dist[end];
}

int main(){

}