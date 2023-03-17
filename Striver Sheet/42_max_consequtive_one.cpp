#include<bits/stdc++.h>
using namespace std;

int MaxConsequtive(int arr[] , int n){
    int c = 0 , mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            c++;
        }
        else
        {
            mx = max(mx , c);
        }
    }
    return mx;
}

int main(){
    int arr[] = {1,1,0,1,1,1};
    cout<<MaxConsequtive(arr , 6)<<endl;
}