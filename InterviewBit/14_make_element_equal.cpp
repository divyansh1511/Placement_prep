#include<bits/stdc++.h>
using namespace std;

int isequal(int arr[] , int n , int k){
    vector<int> v;
    v.push_back(arr[0]);
    v.push_back(arr[0]+k);
    v.push_back(arr[0]-k);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != v[0] && arr[i] != v[1] && arr[i] != v[2] && (arr[i]+k) != v[0] && (arr[i]+k) != v[1] && (arr[i]+k) != v[2] && (arr[i]-k) != v[0] && (arr[i]-k) != v[1] && (arr[i]-k) != v[2])
        {
            return 0;
        }
    }
    return 1;
}

int main(){

}