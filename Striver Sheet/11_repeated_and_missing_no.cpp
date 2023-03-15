#include<bits/stdc++.h>
using namespace std;

vector<int> RepeatedAndMissingNo(int arr[] , int n){
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum -= (i+1);
        squaresum += arr[i]*arr[i];
        squaresum -= (i+1)*(i+1);
    }
    squaresum /= sum;
    int a = (squaresum+sum)/2;
    int b = squaresum - a;
    return {a,b};
}

int main(){
    int arr[] = {3,1,2,5,3};
    vector<int> v = RepeatedAndMissingNo(arr , 5);
    cout<<v[0]<<" "<<v[1]<<endl;
}