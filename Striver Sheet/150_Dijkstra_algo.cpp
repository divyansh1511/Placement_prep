#include<bits/stdc++.h>
using namespace std;

vector<int> DijkstraAlgo(vector<vector<int>> v[], int n , int src){
    vector<int> dis(n , INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int , int>> , greater<pair<int,int>>> pq;
    dis[src] = 0;
    pq.push({0 , src});

    while (!pq.empty())
    {
        int nod = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dis[nod])
        {
            continue;
        }
        
        for(auto it : v[nod]){
            int to = it[0];
            int len = it[1];
            
            if (dis[nod] + len < dis[to])
            {
                dis[to] = dis[nod] + len;
                pq.push({dis[to] , to});
            }
        }
    }
    return dis;
}

int main(){

}