#include<bits/stdc++.h>
using namespace std;

int Kthlargest(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int arr[] = {1,2,6,4,5,3};
    cout<<Kthlargest(arr , 6 , 3)<<endl;
}