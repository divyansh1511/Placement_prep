#include<bits/stdc++.h>
using namespace std;

int Kthlargestele(vector<int> v , int k){
    priority_queue<int,vector<int>, queue<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int main(){

}