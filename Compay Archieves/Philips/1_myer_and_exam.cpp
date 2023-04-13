#include<bits/stdc++.h>
using namespace std;

int MyerExam(int arr[] , int n){
    set<int> s;
    sort(arr , arr+n);
    int mx = arr[0];
    s.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int a = arr[i];
        if (s.count(a))
        {
            arr[i] = mx+1;
            mx++;
            s.insert(mx);
        }
        else
        {
            mx = arr[i];
            s.insert(arr[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr[] = {1,4,5,4,5};
    cout<<MyerExam(arr , 5)<<endl;
}