#include<bits/stdc++.h>
using namespace std;

vector<int> wavearray(vector<int> arr){
    int n = arr.size();
    sort(arr.begin() , arr.end());

    for (int i = 0; i < n; i += 2)
    {
        if (i == n-1)
        {
            break;
        }
        swap(arr[i] , arr[i+1]);
    }
    return arr;
}

int main(){

}